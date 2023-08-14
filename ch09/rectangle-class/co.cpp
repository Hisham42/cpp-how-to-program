#include "co.h"
#include <iostream>

CO::CO(int x1, int y1)
: c1x(x1), c1y(y1)
{
    try
    {
        createCO(x1, y1);
    }
    catch(const char* error)
    {
        std::cout << error << std::endl;
        exit(2);
    }
}

CO::~CO()
{
}

void CO::createCO(int x1, int y1)
{
    /*
    1----------2
     |        |
    3----------4
    */

   if (x1 >=0 && x1 <=20 && y1 >=0 && y1 <= 20)
   {
    c1x = x1;
    c1y = y1;
   }
   else
   {
    throw "x/y Creation Error 101";
   }
   
}


int CO::getX()
{
    return c1x;
}

int CO::getY()
{
    return c1y;
}

void CO::setX(int x)
{
    c1x = x;
}
void CO::setY(int y)
{
    c1y = y;
}

