/*
# i{0}
# counter = cin
#while i <= counter:
    
    if userInput < smallestValue
        smallestValue = userInput
    else
        continue
*/

#include <iostream>

using namespace std;

int main() {

    unsigned int i{0};
    unsigned int counter{0};
    cout << "Please enter the number of values: ";
    cin >> counter;
    unsigned int userInput{0};
    unsigned int smallestValue{0};

    while (i < counter)
    {
        cout << "Please enter the number " << i+1 << ": ";

        cin >> userInput;

        if (i == 0)
        {
            smallestValue = userInput;
        }

        if (userInput < smallestValue)
        {
            smallestValue = userInput;
            ++i;
        }
        
        else
        {
            ++i;
            continue;
        }
        
    }
    
    cout << "The smallest value is " << smallestValue << endl;
    
}