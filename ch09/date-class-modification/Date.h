// Fig. 9.18: Date.h 
// Date class definition; Member functions defined in Date.cpp
#include <string>
#include <array>

#include <sstream>
#include <stdexcept>
#include <iostream>

using namespace std;

#ifndef DATE_H
#define DATE_H


class Date {
public:

   static const unsigned int monthsPerYear{12}; // months in a year
   explicit Date(unsigned int, unsigned int, unsigned int);

   Date();


   string toString() const; // date string in month/day/year format

   string toStringDDDYYYY() const; // date string in DDD YYYY format

   string toStringMDY() const; // date string in DDD YYYY format
   
   ~Date(); // provided to confirm destruction order
private:
   unsigned int month; // 1-12 (January-December)
   unsigned int day; // 1-31 based on month
   unsigned int year; // any year

   // utility function to check if day is proper for month and year
   unsigned int checkDay(int) const;
   unsigned int calculateDDD(unsigned int, unsigned int) const;
   string transformMonth(unsigned int) const;
};

#endif
