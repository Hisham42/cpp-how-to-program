#include <iostream>
using namespace std;

int main() {

    unsigned int counter{0}, number{0}, largest{0};

    while (counter != 10)
    {
        cout << "Enter Number " << counter + 1 << ": ";
        cin >> number;
        

        if (number > largest)
        {
            largest = number;
        }


        counter++;
    }

    cout << "The largest number is " << largest << endl;
}