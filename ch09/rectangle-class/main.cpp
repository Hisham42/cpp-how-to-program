#include <iostream>
#include "rec.h"

using namespace std;

int main()
{
    CO r1 (1, 2);
    CO r2 (16, 2);
    CO r3 (1, 12);
    CO r4 (16, 12);

    Rectangle rec1 (r1, r2, r3, r4);

    if (rec1.isSquare())
    {
        cout << "It is a square." << endl;
    }
    
    cout << "Width: " << rec1.getWidth() << endl;
    cout << "Length: " << rec1.getLength() << endl;
    cout << "Perimeter: " << rec1.getPerimeter() << endl;
    cout << "Area: " << rec1.getArea() << endl;
    rec1.drawRec();
    

}