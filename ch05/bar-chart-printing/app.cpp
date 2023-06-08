#include <iostream>

using namespace std;

void columnPrint(int input);

int main() {

    int userInput1{0}, userInput2{0}, userInput3{0}, userInput4{0}, userInput5{0};

    cout << "Please enter five numbers: ";

    cin >> userInput1;
    cin >> userInput2;
    cin >> userInput3;
    cin >> userInput4;
    cin >> userInput5;

    cout << "--------------------\n";

    columnPrint(userInput1);
    columnPrint(userInput2);
    columnPrint(userInput3);
    columnPrint(userInput4);
    columnPrint(userInput5);
    
}

void columnPrint(int input) {

    for (size_t i = 0; i < input; i++)
    {
        cout << input;
    }
    cout << "\n";
    
    for (size_t i = 0; i < input; i++)
    {
        cout << input;
    }
    cout << "\n";
    
}