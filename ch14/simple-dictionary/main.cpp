#include "Word.h"
#include <fstream>
#include <iomanip>
#include <limits>

// search > in, add > app, view > in,
enum class UserChoice {SEARCH=1, ADD, VIEW, END};
UserChoice enterChoice();
void createDictionary();
void search();
void add();
void view();

int main() {

    ifstream create("dictionary.dat", ios::in | ios::binary);

    if (!create)
    {
        ifstream create2("dictionary.dat", ios::out | ios::binary);
        create2.close();
        createDictionary();
    }

    create.close();

    

    UserChoice choice;
    while ((choice = enterChoice()) != UserChoice::END)
    {
        switch (choice)
        {
        case UserChoice::SEARCH:
            search();
            break;
        
        case UserChoice::ADD:
            add();
            break;
        
        case UserChoice::VIEW:
            view();
            break;
        
        
        default:
            cerr << "Incorrect choice" << endl;
            break;
        }
    }






}

UserChoice enterChoice() {
    cout << "Please Enter Choice: \n"
    << "1 - Search\n"
    << "2 - Add\n"
    << "3 - View\n"
    << "4 - End\n"
    << "? - ";

    int userInput;
    
    cin >> userInput;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
   

    return UserChoice(userInput);
}


void createDictionary() {

    ofstream dict("dictionary.dat", ios::out | ios::binary);

    if (!dict)
    {
        cerr << "Cannot create file" << endl;
    }

    Word blank;

    for (size_t i = 0; i < 100; i++)
    {
        dict.write(reinterpret_cast<const char*>(&blank), sizeof(Word));
    }
    dict.close();

}

void search() {

    string userInput;
    cout << "Please enter word to get its translation: " << endl;

    getline(cin, userInput);

    ifstream dict("dictionary.dat", ios::in | ios::binary);

    if (!dict)
    {
        cerr << "Cannot open file" << endl;
    }

    Word master;
    
    while(dict.read(reinterpret_cast<char*>(&master), sizeof(Word)))
    {
        if (userInput == master.getWord())
        {
            cout << master.getTranslation() << endl;
        }
    }
    dict.close();
}

void add() {

    string word, translation;

    cout << "Please enter word: " << endl;
    cin >> word;

    cout << "Enter Translation: " << endl;
    cin >> translation;

    ofstream dict("dictionary.dat", ios::app | ios::binary);

    if (!dict)
    {
        cerr << "Cannot open file" << endl;
    }

    Word newWord(word, translation);

    dict.write(reinterpret_cast<const char*>(&newWord), sizeof(Word));
    
    dict.close();
}

void view() {

    ifstream dict("dictionary.dat", ios::in | ios::binary);

    if (!dict)
    {
        cerr << "Cannot open file" << endl;
    }

    Word master;
    int i{1};

    cout << left << setw(15) << "No." << setw(15) 
    << "Word" << setw(15) << "Translation" << endl;

    while(dict.read(reinterpret_cast<char*>(&master), sizeof(Word)))
    {
        if (!master.getWord().empty())
        {
            cout << left << setw(15) << i << setw(15) << master.getWord() 
            << setw(15) << master.getTranslation() << endl;
            i++;

        }
    }
    dict.close();
}