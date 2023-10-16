#include <iostream>
#include "array.h"

int main() {

   Array<std::string, 15> a;
   a[2] = "Ahmed";
   std::cout << a[2] << std::endl;
}