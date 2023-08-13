#include <iostream>
#include "rec.h"

using namespace std;

int main()
{
    Rectangle a1(3.4, 4.7);

    cout << a1.getPerimeter() << endl;

    cout << a1.getArea() << endl;


    Rectangle a2(2, 22);

    cout << a2.getPerimeter() << endl;
    cout << a2.getArea() << endl;

}