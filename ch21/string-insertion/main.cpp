#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::string a;
    std::string b;


    std::cin >> a;

    std::string astriks = "******";
    
    for (size_t i = (a.size() / 2); i < a.size(); i++)
    {
        b.push_back(a[i]);
    }
    for (size_t i = 0; i < b.size(); i++)
    {
        a.pop_back();
    }


    a.append(astriks);
    a.append(b);

    std::cout << a << std::endl;
    
}