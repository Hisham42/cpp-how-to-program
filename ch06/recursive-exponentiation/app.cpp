#include <iostream>

using namespace std;

int recursiveExponentiation(int base, int power);

int main() {

    cout << recursiveExponentiation(2, 3) << "\n";

}


int recursiveExponentiation(int base, int power) {

    int number{base};

    if (power == 0)
    {
        return 1;
    }

    number *= recursiveExponentiation(base, power -1);
    
    return number;

}