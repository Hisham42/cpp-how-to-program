#include <iostream>
#include <math.h>
using namespace std;

int main() {
    double a, p{1000.0}, n;
    double r{.05};

    


    for (r = .05; r <= .1; r += .01)
    {
        cout << "Interest Rate: " << r*100 << "%\n";

        for (n = 1; n <= 10; n++)
        {
            cout << "Year: " << n;

            a = p * pow((1 + r), n);
            cout << "\nAmount: $" << a << endl;
        }

        cout << "\n";
        
    }
    
}