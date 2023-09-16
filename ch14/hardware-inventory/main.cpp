// input
// list
// delete
// update
#include "Tool.h"
#include <fstream>
#include <limits>
#include <sstream>
#include <iomanip>

enum class UserChoice {INPUT=1, LIST, DELETE, UPDATE, END};
UserChoice enterChoice();
void performInput();
void list();
void deleteV();
void update();


int main() {

    // create hardware.dat file
    ofstream hardware("hardware.dat", ios::out | ios::binary);

    // initialize it with 100 empty records
    Tool blank;
    for (size_t i = 0; i < 100; i++)
    {
        hardware.write(reinterpret_cast<const char*>(&blank), sizeof(Tool));
    }
    hardware.close();


    // based on user choice, perform a task
    UserChoice choice;
    while ((choice = enterChoice()) != UserChoice::END)
    {
        switch (choice)
        {
        case UserChoice::INPUT:
            performInput();
            break;
        
        case UserChoice::LIST:
            list();
            break;
        
        case UserChoice::DELETE:
            deleteV();
            break;
        
        case UserChoice::UPDATE:
            update();
            break;
        
        default:
            cerr << "Incorrect choice" << endl;
            break;
        }
    }



}

// create a function to let the user choose input
UserChoice enterChoice() {
    cout << "Please Enter Choice: \n"
    << "1 - Input\n"
    << "2 - List\n"
    << "3 - Delete\n"
    << "4 - Update\n"
    << "5 - End\n"
    << "? - ";
    int userInput;
    
    cin >> userInput;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
   

    return UserChoice(userInput);
}


void performInput() {

    string toolString, quantityStr, costStr, toolName;
    unsigned int quantity, record{1};
    double cost;

    
    cout << "Please Enter (Tool_Name, Quantity, Cost)" << endl;
    

    getline(cin, toolString);
    istringstream ss(toolString);

    if (getline(ss, toolName, ',') &&
        getline(ss, quantityStr, ',') &&
        getline(ss, costStr, ','))
    {
        if (!toolName.empty() && toolName[0] == ' ') {
            toolName.erase(0, 1);
        }
        if (!quantityStr.empty() && quantityStr[0] == ' ') {
            quantityStr.erase(0, 1);
        }
        quantity = stoi(quantityStr);
        if (!costStr.empty() && costStr[0] == ' ') {
            costStr.erase(0, 1);
        }
        cost = stod(costStr);
    }

    
    

    fstream hard("hardware.dat", ios::out | ios::in | ios::binary);

    if (!hard) {
        cerr << "Error opening file for reading." << endl;
    }

    Tool reader;
    
    while(hard.read(reinterpret_cast<char*>(&reader), sizeof(Tool)))
    {
        if (record == reader.getRecord())
        {
            record++;
        }
        else
        {
            break;
        }
        
    }

    Tool master(record, toolName, quantity, cost);

    hard.seekp((record - 1) * sizeof(Tool));

    hard.write(reinterpret_cast<const char*>(&master), sizeof(Tool));
    hard.close();

}

void list() {
    ifstream hard("hardware.dat", ios::in | ios::binary);

    if (!hard) {
        cerr << "Error opening file for reading." << endl;
    }

    Tool master;

    cout << left << setw(15) << "Record #" << setw(20) << "Tool name" << setw(15) << "Quantity" 
    << setw(15) << "Cost" << endl; 
    while(hard.read(reinterpret_cast<char*>(&master), sizeof(Tool)))
    {
        if (master.getRecord() != 0)
        {
            cout << left << setw(15) << master.getRecord() << setw(20)
            << master.getToolName() << setw(15)
            << master.getQuantity() << setw(1)
            << "$" << setw(14) << master.getCost() << endl;
        }
    }
    hard.close();
} 

void deleteV() {

    unsigned int userInput;

    cout << "Enter the record number you want to delete: " << endl;

    cin >> userInput;


    fstream hard("hardware.dat", ios::in | ios::out | ios::binary);

    if (!hard) {
        cerr << "Error opening file for reading." << endl;
    }

    Tool master;
    Tool blank;

    while(hard.read(reinterpret_cast<char*>(&master), sizeof(Tool)))
    {
        if (master.getRecord() == userInput)
        {
            hard.seekp(- sizeof(Tool), ios::cur);
            hard.write(reinterpret_cast<const char*>(&blank), sizeof(Tool));
            break;
        }
    }
    hard.close();
}

void update() {

    string strr, newCostStr, newQuantityStr;
    unsigned int userInput{0}, newQuantity{0};
    double newCost;

    cout << "Enter the record number you want to update: " << endl;

    cin >> userInput;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    

    cout << "Please Enter (Quantity, Cost): \n";
    
    getline(cin, strr);

    istringstream iss(strr);

    if (getline(iss, newQuantityStr, ',') &&
        getline(iss, newCostStr, '\n'))
    {
        if (!newQuantityStr.empty() && newQuantityStr[0] == ' ') {
            newQuantityStr.erase(0, 1);
            
        }
        newQuantity = stoi(newQuantityStr);

        if (!newCostStr.empty() && newCostStr[0] == ' ') {
            newCostStr.erase(0, 1);
            
        }
        newCost = stod(newCostStr);
    }

    fstream hard("hardware.dat", ios::in | ios::out | ios::binary);

    if (!hard) {
        cerr << "Error opening file for reading." << endl;
    }

    Tool master;

    while(hard.read(reinterpret_cast<char*>(&master), sizeof(Tool)))
    {
        if (master.getRecord() == userInput)
        {
            master.setQuantity(newQuantity);
            master.setCost(newCost);

            hard.seekp(- sizeof(Tool), ios::cur);
            hard.write(reinterpret_cast<const char*>(&master), sizeof(Tool));
            break;
        }
    }
    hard.close();
}