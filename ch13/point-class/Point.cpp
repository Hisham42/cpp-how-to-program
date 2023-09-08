#include "Point.h"

Point::Point(int x, int y)
{
    setX(x);
    setY(y);
}


Point::Point()
{

}

Point::~Point()
{
}

void Point::setX(int x) {
    xCoordinate = x;
}

void Point::setY(int y) {
    yCoordinate = y;
}

int Point::getX() {
    return xCoordinate;
}

int Point::getY() {
    return yCoordinate;
}


ostream& operator<<(ostream& out, Point& p) {


    if (cin.good())
    {
        cout << "X: " << p.getX()
        << "\nY: " << p.getY() << endl;
    }
    else
    {
        cout << "Incorrect Value" << endl;
    }
    
    return out;
}

istream& operator>>(istream& in, Point& p) {


    in >> p.xCoordinate;
    in >> p.yCoordinate;

    cout << in.good() << endl;

    if (!in.good())
    {
        in.clear(ios::failbit);
    }

    return in;
    
}