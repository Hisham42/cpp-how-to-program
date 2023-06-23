// Fig. 7.21: fig07_21.cpp
// Demonstrating C++ Standard Library class template array.
#include <iostream>
#include <iomanip>
#include <array>   
#include <stdexcept>
using namespace std;

void outputArray(const int arr[], int sizeOfArr); // display the array
void inputArray(int arr[], int sizeOfArr); // input values into the array
void arrayInitializer(int arr[], int arr2[], int size);
bool arrayCompare(int arr[], int arr2[], int size);


int main() {

   
   int integers1[7]; // 7-element array<int>  
   int integers2[10]; // 10-element array<int>
   
   // print integers1 size and contents
   cout << "Size of array integers1 is " << 7
      << "\narray after initialization: ";
   outputArray(integers1, 7);
   
   // print integers2 size and contents
   cout << "\nSize of array integers2 is " << 10
      << "\narray after initialization: ";
   outputArray(integers2, 10);

   // input and print integers1 and integers2
   cout << "\nEnter 17 integers:" << endl;
   inputArray(integers1, 7);
   inputArray(integers2, 10);

   cout << "\nAfter input, the arrays contain:\n" 
      << "integers1: ";
   outputArray(integers1, 7);
   cout << "integers2: ";
   outputArray(integers2, 10);

   // use inequality (!=) operator with array objects
   cout << "\nEvaluating: integers1 != integers2" << endl;

   if (integers1 != integers2) {
      cout << "integers1 and integers2 are not equal" << endl;
   }

   // create array integers3 using integers1 as an         
   // initializer; print size and contents                  
   int integers3[7]; // copy constructor
   arrayInitializer(integers3, integers1, 7);

   cout << "\nSize of array integers3 is " << 7
      << "\narray after initialization: ";
   outputArray(integers3, 7);

   // use overloaded assignment (=) operator              
   cout << "\nAssigning integers2 to integers4:" << endl;
   

   int integers4[10]; // copy constructor
   arrayInitializer(integers4, integers2, 10);

   cout << "integers1: ";
   outputArray(integers1, 7);
   cout << "integers2: ";
   outputArray(integers2, 10);

   // use equality (==) operator with array objects
   cout << "\nEvaluating: integers1 == integers2" << endl;

   if (arrayCompare(integers4, integers2, 10) == true) {
      cout << "integers1 and integers2 are equal" << endl;
   }

   // use square brackets to use the value at location 5 as an rvalue
   cout << "\nintegers1[5] is " << integers1[5];

   // use square brackets to create lvalue
   cout << "\n\nAssigning 1000 to integers1[5]" << endl;
   integers1[5] = 1000;
   cout << "integers1: ";
   outputArray(integers1, 7);

   // attempt to use out-of-range subscript                     
   try {
      cout << "\nAttempt to display integers1.at(15)" << endl;
      cout << integers1[15] << endl; // ERROR: out of range
   }
   catch (out_of_range& ex) {
      cerr << "An exception occurred: " << ex.what() << endl;
   }

}

// output array contents
void outputArray(const int arr[], int sizeOfArr) {

   for (size_t i = 0; i < sizeOfArr; i++)
   {
      cout << arr[i] << " ";
   }

   cout << endl;
}

// input array contents
void inputArray(int arr[], int sizeOfArr) {
   for (size_t i = 0; i < sizeOfArr; i++)
   {
      cin >> arr[i];
   }
}

void arrayInitializer(int arr[], int arr2[], int size) {
   for (size_t i = 0; i < size; i++)
   {
      arr[i] = arr2[i];
   }
}

bool arrayCompare(int arr[], int arr2[], int size) {
   bool x{false};
   for (size_t i = 0; i < size; i++)
   {
      if (arr[i] == arr2[i])
      {
         x = true;
      }
      else {
         x = false;
         break;
      }
   }
   return x;
}




/**************************************************************************
 * (C) Copyright 1992-2014 by Deitel & Associates, Inc. and               *
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
