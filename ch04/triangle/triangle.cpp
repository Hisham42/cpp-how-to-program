#include <iostream>
#include <math.h>

using namespace std;

/*
Write a program that reads three nonzero integers and determines
and prints whether they’re the sides of a right triangle.
*/

int main() {
    unsigned int x;
    unsigned int y;
    unsigned int z;

    cout << "Please Enter the 3 sides: ";
    cout << "\nx: ";
    cin >> x;
    cout << "y: ";
    cin >> y;
    cout << "z: ";
    cin >> z;

    
    if (pow(x, 2) == pow(y, 2) + pow(z, 2))
    {
        cout << "Side of a right triangle" << endl;
    }
    else if (pow(y, 2) == pow(x, 2) + pow(z, 2))
    {
        cout << "Side of a right triangle" << endl;
    }
    else if (pow(z, 2) == pow(x, 2) + pow(y, 2))
    {
        cout << "Side of a right triangle" << endl;
    }
    else
    {
        cout << "Invalid" << endl;
    }
    
    
    



}