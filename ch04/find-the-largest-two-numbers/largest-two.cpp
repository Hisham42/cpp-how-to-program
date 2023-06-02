#include <iostream>
using namespace std;

int main() {

    unsigned int counter{0}, currentNumber{0}, largest{0}, secondLargest{0};

    while (counter != 10)
    {       
        
        cout << "Enter Number " << counter + 1 << ": ";
        cin >> currentNumber;

        if (currentNumber > largest)
        {
            /* code */
            if (largest > secondLargest)
            {
                secondLargest = largest;
            }
            
            largest = currentNumber;
        }

        else if (currentNumber < largest)
        {
            if (currentNumber > secondLargest)
            {
                secondLargest = currentNumber;
            }
        }
        
        

        counter++;
        
    }

    cout << "The largest currentNumber is " << largest << endl;
    cout << "The second largest currentNumber is " << secondLargest << endl;

}