#include <iostream>
#include <cstring>

int main() {


    char a[20];

    std::cin.getline(a, 90);

    const char* searchPtr{"Ahmed"};

    if (searchPtr != nullptr)
    {
        std::cout << strstr(a, searchPtr) << std::endl;
    }

    char* b = strstr(strstr(a, searchPtr) + 1, searchPtr);
    

    if (searchPtr != nullptr)
    {
        std::cout << strstr(b, searchPtr) << std::endl;
    }
    
}