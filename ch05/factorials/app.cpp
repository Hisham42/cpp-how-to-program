#include <iostream>
#include <iomanip>

using namespace std;
long factorialCalculator (int userInput);

int main() {


    for (unsigned int i = 1; i <= 20; i++)
    {
        cout << setw(4) << i << "! = " << factorialCalculator(i) << endl;
    }
    
    
}

long factorialCalculator (int userInput) {
    
    long total{userInput};
    
    int previous = userInput - 1;
    

    if (previous != 0)
    {
        
        total *= factorialCalculator(previous);
    }

    return total;
    
}