// Fig. 10.18: Hugeinteger.cpp 
// HugeInteger member-function and friend-function definitions.
#include <cctype> // isdigit function prototype
#include "HugeInteger.h" // HugeInteger class definition
#include <math.h>
#include <string.h>
using namespace std;

bool HugeInteger::continueDiv = true;

// default constructor; conversion constructor that converts
// a long integer into a HugeInteger object
HugeInteger::HugeInteger(long value) {
   // place digits of argument into array 
   for (int j{digits - 1}; value != 0 && j >= 0; j--) {
      integer[j] = value % 10;
      value /= 10;
   }
}

// conversion constructor that converts a character string 
// representing a large integer into a HugeInteger object
HugeInteger::HugeInteger(const string& number) {
   // place digits of argument into array
   int length= number.size();

   for (int j{digits - length}, k{0}; j < digits; ++j, ++k) {
      if (isdigit(number[k])) { // ensure that character is a digit
         integer[j] = number[k] - '0';
      }
   }
}

// addition operator; HugeInteger + HugeInteger
HugeInteger HugeInteger::operator+(const HugeInteger& op2) const {
   HugeInteger temp; // temporary result
   int carry = 0;

   for (int i{digits - 1}; i >= 0; i--) {
      temp.integer[i] = integer[i] + op2.integer[i] + carry;

      // determine whether to carry a 1
      if (temp.integer[i] > 9) {
         temp.integer[i] %= 10;  // reduce to 0-9
         carry = 1;
      }
      else { // no carry 
         carry = 0;
      }
   }

   return temp; // return copy of temporary object
}

// addition operator; HugeInteger + int
HugeInteger HugeInteger::operator+(int op2) const {
   // convert op2 to a HugeInteger, then invoke 
   // operator+ for two HugeInteger objects
   return *this + HugeInteger(op2);
}

// addition operator;
// HugeInteger + string that represents large integer value
HugeInteger HugeInteger::operator+(const string& op2) const {
   // convert op2 to a HugeInteger, then invoke 
   // operator+ for two HugeInteger objects
   return *this + HugeInteger(op2);
}

// overloaded output operator
ostream& operator<<(ostream& output, const HugeInteger& num) {
   int i;

   // skip leading zeros
   for (i = 0; (i < HugeInteger::digits) && (0 == num.integer[i]); ++i)
   {

   }

   if (i == HugeInteger::digits) {
      output << 0;
   }
   else {
      for (; i < HugeInteger::digits; ++i) {
         output << num.integer[i];
      }
   }

   return output;
}


HugeInteger HugeInteger::operator*(const HugeInteger& op2) const {
   
   HugeInteger temp; // temporary result
   HugeInteger result;
   
   int carry = 0;
   //original multiplication

   for (int j{digits - 1}, k{0}; j >= 0; j--, k++)
   {
      if (op2.integer[j] != 0)
      {
         for (int i{digits - 1}; i >= 0; i--)
         {

            temp.integer[i] = integer[i] * op2.integer[j] + carry;

            //determine whether to carry more than 1

            if (temp.integer[i] > 9)
            {
               int tempMulti = temp.integer[i];

               temp.integer[i] %= 10; // reduce to 0-9
               
               carry = tempMulti / 10;
            }
            else
            {
               carry = 0;
            }
         }
      }
      else
      {
         temp = 0;
      }

      result = result + temp.shift(k);
     
   }
   return result;
}

HugeInteger HugeInteger::shift(int k) {
   if (k > 0)
   {
      HugeInteger temp;

      for (int i = 0; i < digits - k; i++)
      {

         temp.integer[i] = integer[i+k];
      }

      return temp;
   }
   else
   {
      return *this;
   }
}

HugeInteger HugeInteger::operator*(int x) const {
   return (*this * HugeInteger(x));
}

HugeInteger HugeInteger::operator*(const std::string& s) const {
   return (*this * HugeInteger(s));
}

HugeInteger HugeInteger::divide(const HugeInteger& op2) const {
   if (*this < op2)
   {
      return HugeInteger(0);
   }
   else if (*this == op2)
   {
      return HugeInteger(1);
   }
   else if (op2 == HugeInteger(1))
   {
      return op2;
   }
   
   else
   {
      HugeInteger temp;

      HugeInteger division(2);

      temp = division * op2;

      while (temp < *this)
      {
         division = division + 1;
         temp = division * op2;

         if (temp == *this)
         {
            return division;
         }
         
      }

      return division - 1;
   }
}

HugeInteger HugeInteger::operator/(const HugeInteger& op2) const {
   HugeInteger temp1;

   continueDiv = true;

   HugeInteger neww{*this};
   
   HugeInteger tempSub;
   
   int x;

   if (*this < op2)
   {
      return 0;
   }
   

   int valueStart{digits-realSize()};

   for (int i = 0; i < realSize(); i++)
   {
      if (continueDiv == false)
      {
         break;
      }
      
      x = i;
      temp1.integer[valueStart + i] = temp1.integer[valueStart + i] + ( concatinate(i + 1) / op2.concatinate() );

      if (concatinate(i + 1) / op2.concatinate() == 0)
      {
         continue;
      }
      else
      {
         tempSub = temp1.integer[valueStart + i] * op2.concatinate();
         tempSub = tempSub.shift(realSize() - 1 - i);
         
         neww = *this - tempSub;

         if (neww < op2)
         {
            continueDiv = false;
            break;
         }
         else
         {
            temp1 = temp1 + neww / op2;
         }
         
      }

   }

   

   return temp1;
}

HugeInteger HugeInteger::operator=(const HugeInteger& op2) {
   for (size_t i = 0; i < digits; i++)
   {
      integer[i] = op2.integer[i];
   }

   return *this;
   
}

bool HugeInteger::operator==(const HugeInteger& op2) const {
   for (size_t i = 0; i < digits; i++)
   {
      if (integer[i] != op2.integer[i])
      {
         return false;
      }
      
   }

   return true;
   
}

bool HugeInteger::operator!=(const HugeInteger& op2) const {
   return !operator==(op2);
}

HugeInteger HugeInteger::operator-(const HugeInteger& op2) const {
   if (*this < op2)
   {
      throw invalid_argument("Cannot subtract.");
   }
   else if (*this == op2)
   {
      return HugeInteger(0);
   }
   else
   {
      int rest{0};
      int sub;
      HugeInteger temp;

      for (int i = digits - 1; i > 0; i--)
      {
         sub = integer[i] - op2.integer[i] - rest;

         if (sub >= 0)
         {
            temp.integer[i] = sub;
         }
         else
         {
            temp.integer[i] = 10 + sub;
            rest = 1;
         }
         
         if (digits - i >= this->realSize() && digits - i >= op2.realSize())
         {
            break;
         }
      }
      return temp;
   }
}

int HugeInteger::realSize() const {
   int digitsCountThis{0};
   

   int i{0}; // index of the first number in this

   for (; i < digits; i++)
   {
      if (integer[i] != 0)
      {
         break;
      }
   }

   digitsCountThis = digits - i;

   return digitsCountThis;
}

bool HugeInteger::operator<(const HugeInteger& op2) const {

   if (*this == op2)
   {
      return false;
   }
   
   int digitsCountThis{this->realSize()};
   int digitsCountOp2{op2.realSize()};

   if (digitsCountThis == digitsCountOp2)
   {
      for (size_t z = (digits-digitsCountThis); z < digits; z++)
      {
         if (integer[z] < op2.integer[z])
         {
            return true;
         }
         else if (integer[z] == op2.integer[z])
         {
            continue;
         }
         else
         {
            return false;
         }
      
      }
   }

   else if (digitsCountThis < digitsCountOp2)
   {
      return true;
   }
   else
   {
      return false;
   }

   return false;
   
}

bool HugeInteger::operator>(const HugeInteger& op2) const {
   if (*this == op2)
   {
      return false;
   }

   if (op2 < *this)
   {
      return true;
   }
   else
   {
      return false;
   }
}

HugeInteger HugeInteger::operator-(int a) const {
   return *this - HugeInteger(a);
}

int HugeInteger::concatinate() const {
   int value{};
   int j{realSize() - 1};

   for (int i = digits - realSize(); i < digits; i++)
   {
      value += integer[i] * pow(10, j);
      j--;
      
   }
   
   return value;

}

int HugeInteger::concatinate(int num) const {
   if (num > realSize())
   {
      throw invalid_argument("Invalid concatination");
   }
   
   int value{};
   int j{0};

   for (int i = (digits - realSize() + num - 1); num > 0; i--, num--)
   {
      value += integer[i] * pow(10, j);
      j++;
      
   }
   
   return value;

}

