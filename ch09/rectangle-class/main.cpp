#include <iostream>
#include "rec.h"

using namespace std;

int main()
{
    Rectangle a1(12, 4);

    cout << a1.getPerimeter() << endl;

    cout << a1.getArea() << endl;


    Rectangle a2(4, 12);

    cout << a2.getPerimeter() << endl;
    cout << a2.getArea() << endl;

}