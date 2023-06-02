#include <iostream>
using namespace std;

bool fiveDigitCheck(unsigned int five);

int main() {



    unsigned int userInput{22};
    unsigned int counter{0};

    unsigned int first{0};
    unsigned int second{0};
    unsigned int third{0};
    unsigned int forth{0};
    unsigned int fifth{0};

    while (fiveDigitCheck(userInput) == false)
    {
        cout << "Please enter five digits int: ";
        cin >> userInput;
    }

    
    first = userInput % 10;
    userInput /= 10;


    second = userInput % 10;
    userInput /= 10;

    
    third = userInput % 10;
    userInput /= 10;

    
    forth = userInput % 10;
    userInput /= 10;

    
    fifth = userInput % 10;


    if (first == fifth && second == forth)
    {
        cout << "Valid Palindrome";
    }
    else
    {
        cout << "Invalid Palindrome";
    }
    cout << endl;
    
    
    



}

bool fiveDigitCheck(unsigned int five){

    int x{0};

    while (five !=0)
    {
        five /= 10;
        x++;
    }

    if (x == 5)
    {
        return true;
    }
    else
        return false;
    
    


}

//user input
//check if it is 5 digits?
//divide it by 10 5 times should equal 0
//