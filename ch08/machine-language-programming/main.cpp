#include <iostream>
#include <array>
#include <string>
#include <iomanip>

using namespace std;

enum OPERATIONS
{
    read=10, wirte=11, load=20, store=21, add=30, subtract=31, divide=32, multiply=33, branch=40,
    branchneg=41, breanchzero=42, halt=43
};

int OPERATIONCODE{0};
int OPERAND{0};

int COMPUTERMEMORY[100];
int INSTRUCTIONCOUNTER{0};

string INSTRUCTIONREG{"+0000"};

int ACCUMULATOR{0};

bool HALT{false};
bool VALIDATED{false};


bool validate(string);
void process(string input);
void displaySML();
void displayWelcome();

int main() {

    displayWelcome();

    string userInput;

    int i{0};

    while (!HALT)
    {
        while (!VALIDATED)
        {
            
            cout << setw(2) << setfill('0') << i << " ? " << setfill(' ');
            cin >> userInput;

            if (validate(userInput))
            {
                VALIDATED = true;
                INSTRUCTIONREG = userInput;
            }
            
        }

        process(userInput);

        VALIDATED = false;
        i++;
    }


}


bool validate(string input){

    if (input.length() != 5)
    {
       
        return false;
    }

    else if (input[0] != '+')
    {
        
        return false;
    }

    else
    {
        for (size_t i = 1; i < 5; i++)
        {
            

            if (input[i] > 57 || input[i] < 48)
            {
                
                return false;
            }
            
        }

        
        return true;
    }
    
}

void process(string input) {

    int operation = (input[2] - 48) + (input[1] - 48) * 10;
    int location = (input[4] - 48) + (input[3] - 48) * 10;

    switch (operation)
    {
    case read:
        
        cin >> COMPUTERMEMORY[location];
        INSTRUCTIONCOUNTER++;
        OPERATIONCODE = read;
        OPERAND = location;

        break;

    case wirte:
        cout << COMPUTERMEMORY[location] << endl;
        INSTRUCTIONCOUNTER++;
        OPERATIONCODE = wirte;
        OPERAND = location;
        break;

    case load:
        ACCUMULATOR = COMPUTERMEMORY[location];
        INSTRUCTIONCOUNTER++;
        OPERATIONCODE = load;
        OPERAND = location;
        break;

    case store:
        COMPUTERMEMORY[location] = ACCUMULATOR;
        INSTRUCTIONCOUNTER++;
        OPERATIONCODE = store;
        OPERAND = location;
        break;

    case add:
        ACCUMULATOR += COMPUTERMEMORY[location];
        INSTRUCTIONCOUNTER++;
        OPERATIONCODE = add;
        OPERAND = location;
        break;

    case subtract:
        ACCUMULATOR -= COMPUTERMEMORY[location];
        INSTRUCTIONCOUNTER++;
        OPERATIONCODE = subtract;
        OPERAND = location;
        break;

    case divide:
        ACCUMULATOR /= COMPUTERMEMORY[location];
        INSTRUCTIONCOUNTER++;
        OPERATIONCODE = divide;
        OPERAND = location;
        break;

    case multiply:
        ACCUMULATOR *= COMPUTERMEMORY[location];
        INSTRUCTIONCOUNTER++;
        OPERATIONCODE = multiply;
        OPERAND = location;
        break;

    case branch:
        INSTRUCTIONCOUNTER++;
        OPERATIONCODE = branch;
        OPERAND = location;
        break;

    case branchneg:
        INSTRUCTIONCOUNTER++;
        OPERATIONCODE = branchneg;
        OPERAND = location;
        break;

    case breanchzero:
        INSTRUCTIONCOUNTER++;
        OPERATIONCODE = breanchzero;
        OPERAND = location;
        break;

    case halt:
        HALT = true;
        cout << "*** Simpletron execution terminated ***" << endl;
        displaySML();
        break;
    
    default:
        break;
    }

}

void displaySML(){

    cout << setw(20) << left << "REGISTERS:" << endl;
    cout << setw(20) << left << "accumulator" << setw(10) << right << showpos << ACCUMULATOR << endl;
    cout << setw(20) << left <<  "instructionCounter" << setw(10) << right << noshowpos << INSTRUCTIONCOUNTER <<endl;
    cout << setw(20) << left <<  "instructionRegister" << setw(10) << right << noshowpos << INSTRUCTIONREG << endl;
    cout << setw(20) << left <<  "operationCode" << setw(10) << right << noshowpos << OPERATIONCODE << endl;
    cout << setw(20) << left <<  "operand" << setw(10) << right << noshowpos << OPERAND << endl;

    cout << "\nMEMORY: " << endl;
    cout << setw(3) << " ";

    for (size_t i = 0; i < 10; i++)
    {
        cout << setw(5) << i;
        cout << setw(1) << " ";
    }

    cout << endl;

    for (size_t i = 0; i < 100; i += 10)
    {
        cout << setw(2) << i << " ";
        
        for (size_t j = 0; j < 10; j++)
        {
            cout << showpos << setw(5) << COMPUTERMEMORY[j+i] << " ";
        }
        cout << endl;

    }
}

void displayWelcome() {
    cout << "*** Welcome to Simpletron! ***\n"
    << "*** Please enter your program one instruction ***\n"
    << "*** (or data word) at a time. I will type the ***\n"
    << "*** location number and a question mark (?).  ***\n"
    << "*** You then type the word for that location. ***\n"
    << "*** Type the sentinel -99999 to stop entering ***\n"
    << "*** your program. ***" << endl;
}