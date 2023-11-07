#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::string a{""};
    std::string b{""};
    std::cin >> a;
    std::cin >> b;

    std::string c = a + " " + b;

    std::stringstream d{""};
    d << a;
    d << ' ';
    d << b;

    std::cout << c << "\n";
    std::cout << d.str() << std::endl;
    
}