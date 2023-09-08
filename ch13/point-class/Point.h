#ifndef POINT_H
#define POINT_H


#include <iostream>
#include <iomanip>

using namespace std;

class Point
{
private:
    int xCoordinate, yCoordinate;

public:

    friend ostream& operator<<(ostream&, Point&);
    friend istream& operator>>(istream&, Point&);




    Point(int, int);
    Point();
    ~Point();

    void setX(int);
    void setY(int);

    int getX();
    int getY();
};




#endif