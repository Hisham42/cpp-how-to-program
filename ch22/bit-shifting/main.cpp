#include <iostream>
#include <bitset>


    int power2(int number, int power) {
        
        int y{0};

        for (size_t i = 0; i < power; i++)
        {
            number <<= 1;
            y = number;
        }

        return y;
        
    }


    int devide2(int number, int power) {
        
        int y{0};

        for (size_t i = 0; i < power; i++)
        {
            number >>= 1;
            y = number;
        }

        return y;
        
    }

int main() {
  

    std::cout << power2(50, 2) << std::endl;

    std::cout << devide2(50, 2) << std::endl;

}