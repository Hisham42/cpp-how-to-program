#include <iostream>

unsigned int setBit(const unsigned int& num, unsigned int bitPosition) {
    int x = 0b0001;  // 0010
    for (size_t i = 0; i < bitPosition; i++)
    {
        x <<= 1;
    }
    
    return x | num;
}

int main() {

    std::cout << setBit(12, 2) << std::endl;
}