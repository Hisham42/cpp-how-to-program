#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::string a;
    std::stringstream b;

    getline(std::cin, a);

    while (a.find("BY") != std::string::npos)
    {
        a.erase(a.find("BY"), 2);
    }

    while (a.find("by") != std::string::npos)
    {
        a.erase(a.find("by"), 2);
    }
    
    std::cout << a << std::endl;  
    
}