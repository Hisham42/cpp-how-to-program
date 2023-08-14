#ifndef REC_H
#define REC_H


class Rectangle
{
private:
    double length, width;
public:
    Rectangle(double len=1, double wid=1);
    ~Rectangle();

    //getters
    double getPerimeter();
    double getArea();
    double getLength();
    double getWidth();

    //setters
    void setLength(double l);
    void setWidth(double w);

};


#endif