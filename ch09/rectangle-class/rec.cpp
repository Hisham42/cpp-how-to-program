#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <string>



#include "rec.h"

std::string rect[25][50];




Rectangle::Rectangle(CO cc1, CO cc2, CO cc3, CO cc4)
: rc1(cc1), rc2(cc2), rc3(cc3), rc4(cc4)
{
    try
    {
        setRectangle(cc1, cc2, cc3, cc4);
    }
    
    catch(const char* error)
    {
        std::cout << error << std::endl;
        exit(1);
    }
    
    
}

Rectangle::~Rectangle()
{
}

void Rectangle::setRectangle(CO c1, CO c2, CO c3, CO c4)
{
    if (
        c1.getX() == c3.getX() && c2.getX() == c4.getX() && c1.getY() == c2.getY() && c3.getY() == c4.getY()
        && c1.getY() < c3.getY() && c1.getX() < c2.getX()
    )

    {
        std::cout << "Rectangular was created successfully" << std::endl;
        rc1.setX(c1.getX());
        rc1.setY(c1.getY());
        rc2.setX(c2.getX());
        rc2.setY(c2.getY());
        rc3.setX(c3.getX());
        rc3.setY(c3.getY());
        rc4.setX(c4.getX());
        rc4.setY(c4.getY());

        width = getWidth();
        length = getLength();

    }
    else
    {
        throw "Rec Creation Error 1015";
    }
    
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
    if (abs(rc1.getX() - rc2.getX()) > abs(rc1.getY() - rc3.getY()))
    {
        length = abs(rc1.getX() - rc2.getX());
    }
    else
    {
        length = abs(rc1.getY() - rc3.getY());
    }
    
    return length;
}

double Rectangle::getWidth()
{
    if (abs(rc1.getX() - rc2.getX()) > abs(rc1.getY() - rc3.getY()))
    {
        width = abs(rc1.getY() - rc3.getY());
        
    }
    else
    {
        width = abs(rc1.getX() - rc2.getX());
    }

    return width;
}

bool Rectangle::isSquare()
{
    if (length == width)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

void recPlotter(int x, int y, char perC)
{
    rect[24 - y][x] = perC;
}

void Rectangle::drawRec(char perimeterC, char fillC, int scale)
{
    //draw axis
   

    for (size_t i = 0; i < 25; i++)
    {
        for (size_t j = 0; j < 25; j++)
        {
            rect[i][j] = fillC;
        }
    }

    for (size_t i = 0; i < 25; i++)
    {
        rect[i][0] = "|";
        
    }

    for (size_t i = 0; i < 25; i++)
    {
        rect[24][i] = "___";
        
    }

    // plot initial points
    recPlotter(rc1.getX(), rc1.getY(), perimeterC);
    recPlotter(rc2.getX(), rc2.getY(), perimeterC);
    recPlotter(rc3.getX(), rc3.getY(), perimeterC);
    recPlotter(rc4.getX(), rc4.getY(), perimeterC);


   for (size_t i = 1; i < (rc2.getX() - rc1.getX()); i++)
   {
        recPlotter(rc1.getX() + i, rc1.getY(), perimeterC);
        recPlotter(rc3.getX() + i, rc3.getY(), perimeterC);
   }

   for (size_t i = 1; i < (rc3.getY() - rc1.getY()); i++)
   {
        recPlotter(rc1.getX(), rc1.getY() + i, perimeterC);
        recPlotter(rc2.getX(), rc2.getY() + i, perimeterC);
   }
        
        //h2
        //v1
        //v2

    //draw array

    for (size_t i = 0; i < 25; i++)
    {
        for (size_t j = 0; j < 25; j++)
        {
            std::cout << std::setw(scale) << rect[i][j];
        }
        std::cout << std::endl;
        
    }
    
    

     
}