#include <iostream>
#include <string>
#include <sstream>



int main() {
    
    std::string a;

    std::getline(std::cin, a);

    std::stringstream b;

    for (auto i = a.begin(); i != a.end(); i++)
    {
        b << char(toupper(*i));
    }
    
    
    std::cout << b.str();
    
    

  
}