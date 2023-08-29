// Fig. 10.17: Hugeinteger.h 
// HugeInteger class definition.
#ifndef HugeInteger_H
#define HugeInteger_H

#include <array>
#include <iostream>
#include <string>

class HugeInteger {
   friend std::ostream& operator<<(std::ostream&, const HugeInteger&);
public:
   static const int digits{40}; // maximum digits in a HugeInteger

   HugeInteger(long = 0); // conversion/default constructor
   HugeInteger(const std::string&); // conversion constructor

   // addition operator; HugeInteger + HugeInteger
   HugeInteger operator+(const HugeInteger&) const;

   // addition operator; HugeInteger + int
   HugeInteger operator+(int) const;

   // HugeInteger + string that represents large integer value
   HugeInteger operator+(const std::string&) const;

   // multiplication operator; HugeInteger * HugeInteger
   HugeInteger operator*(const HugeInteger&) const;

   // multiplication operator; HugeInteger * int
   HugeInteger operator*(int) const;

   // HugeInteger * string that represents large integer value
   HugeInteger operator*(const std::string&) const;

   HugeInteger operator=(const HugeInteger& op2) ;
   // division operator; HugeInteger / HugeInteger
   HugeInteger divide(const HugeInteger&) const;

   HugeInteger operator/(const HugeInteger&) const;


   // subtraction operator; HugeInteger + int
   HugeInteger operator-(const HugeInteger& op2) const;

   HugeInteger operator-(int) const;

   

   int realSize() const;

   bool operator==(const HugeInteger& op2) const;
   bool operator!=(const HugeInteger& op2) const;

   bool operator>(const HugeInteger& op2) const;
   bool operator<(const HugeInteger& op2) const;

private:
   std::array<short, digits> integer{}; // default init to 0s
   HugeInteger shift(int);
   int concatinate() const;
   int concatinate(int) const;

   static bool continueDiv; // global counter

};


#endif

