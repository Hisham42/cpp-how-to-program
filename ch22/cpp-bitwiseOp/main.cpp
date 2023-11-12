#include <iostream>
#include <bitset>

int main() {
    int i = 0b10011110;
    int j = 0b01110000;

    std::cout << std::bitset<8>(i) << std::endl;
    std::cout << std::bitset<8>(j) << std::endl;
    std::cout << "------------------------" << std::endl;

    std::cout << "& " << std::bitset<8>(i & j) << std::endl;
    std::cout << "| " << std::bitset<8>(i | j) << std::endl;
    std::cout << "^ " << std::bitset<8>(i ^ j) << std::endl;
    std::cout << "i << " << std::bitset<8>(i << 1) << std::endl;
    std::cout << "j >> " << std::bitset<8>(j >> 2) << std::endl;
    std::cout << "~j " << std::bitset<8>(~j) << std::endl;

}