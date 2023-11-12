#include <iostream>

int main() {


    short x{1};
    int y{2};
    long z{3};


    std::cout << sizeof(x) << std::endl;
    std::cout << sizeof(y) << std::endl;
    std::cout << sizeof(z) << std::endl;



    std::cout << &x << std::endl;
    std::cout << &y << std::endl;
    std::cout << &z << std::endl;


    if (reinterpret_cast<uintptr_t>(&z) - reinterpret_cast<uintptr_t>(&y) > 0 && reinterpret_cast<uintptr_t>(&y) - reinterpret_cast<uintptr_t>(&x) > 0)
    {
        std::cout << "Big Endian" << std::endl;
    }
    else
    {
        std::cout << "Small Endian" << std::endl;
    }
  






} 
