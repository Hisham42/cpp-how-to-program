#include <stdexcept>
#include <iostream>

#include "rec.h"


Rectangle::Rectangle(double len, double wid)
{
    try
    {
        setLength(len);
        setWidth(wid);
    }
    
    catch(...)
    {
        std::cout << "error" << std::endl;
    }
    
    
}

Rectangle::~Rectangle()
{
}

double Rectangle::getPerimeter()
{
    return ((length + width) * 2);
}

double Rectangle::getArea()
{
    return (length * width);
}

double Rectangle::getLength()
{
    return length;
}

double Rectangle::getWidth()
{
    return width;
}

void Rectangle::setLength(double l)
{
    if (l >= 0 && l <=20)
    {
        length = l;
    }
    else
    {
        throw "Length Error 101";
    }
    
    
}

void Rectangle::setWidth(double w)
{
    if (w >= 0 && w <=20)
    {
        width = w;
    }
    else
    {
        throw "Width Error 103";
    }
}