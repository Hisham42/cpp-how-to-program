#include <iostream>
#include <math.h>

using namespace std;


int factorialCalculator(unsigned int x);

int main() {

    unsigned int accuracy{0},counter{1};
    double x;

    cout << "Please enter the accuracy: ";
    cin >> accuracy;
    x = accuracy;
    

    double e{1.0};

    while (accuracy >= counter)
    {
        e += pow(x, counter) / factorialCalculator(counter);
        
        counter++;
        
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