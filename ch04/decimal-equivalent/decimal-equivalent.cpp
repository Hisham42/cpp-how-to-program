/*
Input an integer containing only 0s
and 1s (i.e., a “binary” integer) and print its decimal equivalent. Use the remainder and division 
operators to pick off the “binary” number’s digits one at a time from right to left. Much as in the 
decimal number system, where the rightmost digit has a positional value of 1, the next digit left has a
positional value of 10, then 100, then 1000, and so on, in the binary number system the rightmost
digit has a positional value of 1, the next digit left has a positional value of 2, then 4, then 8, and so
on. Thus the decimal number 234 can be interpreted as 2 * 100 + 3 * 10 + 4 * 1. The decimal 
equivalent of binary 1101 is 1 * 1 + 0 * 2 + 1 * 4 + 1 * 8 or 1 + 0 + 4 + 8, or 13.
*/

#include <iostream>
#include <math.h>

using namespace std;

bool validateInput(unsigned int input);

int main() {


    unsigned int userInput{555};
    unsigned int x{0};
    unsigned int z{0};
    unsigned int totalNumber{0};

    while (validateInput(userInput) == false)
    {
        cout << "Please enter binary number: ";
        cin >> userInput;
    }
    

    while (userInput != 0)
    {
        x = userInput % 2;

        totalNumber = totalNumber +  x * pow(2, z);

        userInput /= 10;

        z++;

    }

    cout << "Binary equivalent is: " << totalNumber << endl;


}


bool validateInput(unsigned int input) {


    unsigned int x;

    while (input != 0)
    {
        x = input % 10;

        if (x > 1)
        {
            return false;
        }
        else
        {
            input /= 10;
        }
    }

    return true;
    

}