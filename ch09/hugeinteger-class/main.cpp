#include <iostream>
#include "huge.h"

using namespace std;

int main()
{
    Huge bigInt1("-1285");
    Huge bigInt2("1285");

    bigInt1.output();
    bigInt2.output();

    if (bigInt1.isEqualTo(bigInt2))
    {
        cout << "Is Equal" << endl;
    }

    if (bigInt1.isNotEqualTo(bigInt2))
    {
        cout << "Is Not Equal" << endl;
    }

    if (bigInt1.isGreaterThan(bigInt2))
    {
        cout << "Is Greater" << endl;
    }

    if (bigInt1.isGreaterThanOrEqualTo(bigInt2))
    {
        cout << "Is Greater Than or equal to" << endl;
    }

    if (bigInt1.isLessThanOrEqualTo(bigInt2))
    {
        cout << "Is Less Than or equal to" << endl;
    }
    
    bigInt1.add(bigInt2);
    bigInt1.subtract(bigInt2);
    bigInt2.add(bigInt1);
    bigInt2.subtract(bigInt1);

}