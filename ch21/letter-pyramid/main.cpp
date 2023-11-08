#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

void printRest(std::stringstream& ss) {
    std::string rest;

    ss >> rest;

    for (auto i = rest.rbegin() + 1; i != rest.rend(); i++)
    {
        std::cout << char(*i);
    }
    
}

int main() {
    
    int width = 15;
    char character = 'a';
    char zero = 'a';
    int characterToBePrinted{1};
    for (int i = width - 1; i > 0; i--)
    {
        std::stringstream strMemory;
        std::cout << std::setw(i);

        character = zero;

        for (size_t j = 0; j < characterToBePrinted; j++)
        {
            std::cout << character;
            strMemory << character;
            ++character;
        }

        printRest(strMemory);
        
        ++zero;
        ++characterToBePrinted;
        
        std::cout << std::endl;

        
    }
    
    

}