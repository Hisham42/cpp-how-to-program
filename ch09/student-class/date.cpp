#include <sstream>
#include <string>
#include <iostream>
#include "date.h" // include definition of class Date from Date.h
using namespace std;

// Date constructor (should do range checking)
Date::Date(unsigned int m, unsigned int d, unsigned int y) 
   
   {

        try
        {
            setDate(m, d, y);
        }
        catch(...)
        {
            std::cout << "Invalid Date" << std::endl;
        }
        
        
        
   }

// print Date in the format mm/dd/yyyy
string Date::toString() const {
   ostringstream output;
   output << month << '/' << day << '/' << year;
   return output.str();
}

void Date::setDate(unsigned int m, unsigned int d, unsigned int y)
{
    if (y <= 2000 && d <= 31 && m <= 12)
        {
            month = m;
            day = d;
            year = y;
        }
        else
        {
            throw 105;
        }
}