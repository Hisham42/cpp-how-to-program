#include <iostream>

using namespace std;

int factorialCalculator(unsigned int x);

int main() {

    unsigned int accuracy{0};

    cout << "Please enter the accuracy: ";
    cin >> accuracy;

    double e{1};

    while (accuracy != 0)
    {
        e += 1.0 / factorialCalculator(accuracy);
        accuracy--;
    }

    cout << "e = " << e << endl;
}

int factorialCalculator(unsigned int x) {
    
    unsigned int factorial{1};

    while(x != 0)
    {
        factorial *= x;
        x--;
    }

    return factorial;
}