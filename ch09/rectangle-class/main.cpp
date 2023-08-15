#include <iostream>
#include "rec.h"


using namespace std;

int main()
{
    // assume it this way
    /*
     r3     r4
     r1     r2
    */

    CO r1 (5, 7);
    CO r2 (15, 7);
    CO r3 (5, 20);
    CO r4 (15, 20);

    Rectangle rec1 (r1, r2, r3, r4);

    if (rec1.isSquare())
    {
        cout << "It is a square." << endl;
    }
    
    cout << "Width: " << rec1.getWidth() << endl;
    cout << "Length: " << rec1.getLength() << endl;
    cout << "Perimeter: " << rec1.getPerimeter() << endl;
    cout << "Area: " << rec1.getArea() << endl;
    rec1.drawRec('#', '\'', 2);

    
    

}