// Fig. 6.25: fig06_25.cpp
// Recursive function factorial.
#include <iostream>
#include <iomanip>
using namespace std;

double i = 1;

unsigned long factorial(unsigned long); // function prototype

int main() {
   // calculate the factorials of 0 through 10
   cout << setw(1) << factorial(12)
         << endl;
   
}

// recursive definition of function factorial   
unsigned long factorial(unsigned long number) {

   

   if (number <= 1) { // test for base case   
         cout << setw(i) << number << "! = 1" << endl;
         i += 9;
      return 1; // base cases: 0! = 1 and 1! = 1
   }
   else { // recursion step    
      cout << setw(i) << number << "! = " << number << " * " << number - 1 << "!" << endl; 
      i += 12;                
      return number * factorial(number - 1);
   }
   
}

/*************************************************************************
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
*************************************************************************/
