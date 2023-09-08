// Fig. 10.4: PhoneNumber.cpp
// Overloaded stream insertion and stream extraction operators
// for class PhoneNumber.
#include <iomanip>
#include "PhoneNumber.h"
#include <limits>
using namespace std;

// overloaded stream insertion operator; cannot be a member function
// if we would like to invoke it with cout << somePhoneNumber; 
ostream& operator<<(ostream& output, const PhoneNumber& number) {
   output << "Area code: " << number.areaCode << "\nExchange: "
      << number.exchange << "\nLine: " << number.line << "\n"
      << "(" << number.areaCode << ") " << number.exchange << "-"
      << number.line << "\n";
   return output; // enables cout << a << b << c;                
}

// overloaded stream extraction operator; cannot be a member function
// if we would like to invoke it with cin >> somePhoneNumber;
istream& operator>>(istream& input, PhoneNumber& number) {
   
   const int maxLength = 14;

   string myString;

   while(true)
   {
      getline(input, myString);

      if (myString.length() != maxLength || myString[0] != '('
         || myString[4] != ')' || myString[5] != ' ' || myString[9] != '-')
      {
         input.clear(ios::failbit);
         
         cout << "phone number is not in the form (555) 555-5555" << endl;
      }
      else if (myString[1] == '0' || myString[1] == '1')
      {
         input.clear(ios::failbit);
         
         cout << "phone number neither starts with 0 nor 1" << endl;
      }
      else if (myString[2] != '0' && myString[2] != '1')
      {
         input.clear(ios::failbit);
         
         cout << "Area code middle digit should be limited to 0 or 1" << endl;
      }
      
      else
      {   
         number.areaCode = myString.substr(1, 3);
         number.exchange = myString.substr(6, 3);
         number.line = myString.substr(10, 4);
      }

      if (cin.good())
      {
         break;
      }
      else {
         cin.clear();
         
      }
      
   }

   
   
   return input; // enables cin >> a >> b >> c;             
}


/**************************************************************************
 * (C) Copyright 1992-2017 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/
