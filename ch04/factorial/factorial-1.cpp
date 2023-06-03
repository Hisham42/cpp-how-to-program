#include <iostream>

using namespace std;

int main() {

    unsigned int n, userInput;
    unsigned int factorial{1};

    cout << "Please enter a positive number: ";
    cin >> n;
    userInput = n;

    while(n != 0)
    {
        factorial *= n;
        n--;
    }

    cout << "Factorial of " << userInput << " is: " << factorial << endl;

}