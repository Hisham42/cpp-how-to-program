#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::string a{""};

    getline(std::cin, a);

    std::stringstream b{""};

    bool upper{true};

    for (auto i = a.begin(); i != a.end(); i++)
    {
        if ((*i) == ' ')
        {
            upper = true;
            b << ' ';
        }
        else if (upper == true)
        {
            b << char(toupper(*i));
            upper = false;
        }
        else 
        {
            b << *i;
        }
    }

    std::cout << b.str() << std::endl;
    
}