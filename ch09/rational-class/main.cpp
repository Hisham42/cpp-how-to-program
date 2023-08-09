#include <iostream>
#include "rational.h"


using namespace std;

int main()
{
    Rational x(5,3);

    x.getFraction();

    Rational y(3,10);

    y.getFraction();

    x.divide(y);
    x.getFraction();


    cout << x.toRationalString() << endl;

    cout << x.toDouble() << endl;
}
