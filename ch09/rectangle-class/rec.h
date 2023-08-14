#include "co.h"

#ifndef REC_H
#define REC_H


class Rectangle
{
private:
    CO rc1, rc2, rc3, rc4;
    double length, width;
public:
    Rectangle(CO c1, CO c2, CO c3, CO c4);
    ~Rectangle();

    //predicate
    bool isSquare();

    //getters
    double getPerimeter();
    double getArea();
    double getLength();
    double getWidth();

    //setters
    void setRectangle(CO c1, CO c2, CO c3, CO c4);

    //void
    void drawRec();

};


#endif