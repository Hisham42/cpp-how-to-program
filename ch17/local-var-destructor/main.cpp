#include <iostream>
#include "NoRealRootException.h"

void function3() {
    std::cout << "Function 3" << "\n";
    throw(std::runtime_error("fun1"));

}

void function2() {
    std::cout << "Function 2" << "\n";
    function3();

}

void function1() {
    std::cout << "Function 1" << "\n";
    function2();
    
}



int main() {

    try
    {
        function1();
    }
    catch(const std::exception& e)
    {
        std::cerr << "catch in main"<< '\n';
    }
   
}



