// Fig. 10.19: fig10_19.cpp
// HugeInteger test program.
#include <iostream>
#include "HugeInteger.h"
using namespace std;

int main() {
   HugeInteger n1{99999999999999};
   HugeInteger n2{13};

   HugeInteger n3{10};

   

   cout << "Result / << " << n1 / n2 << endl;

   cout << "Result / << " << n2 / n3 << endl;

   cout << "Result / << " << n3 / n3 << endl;


}

