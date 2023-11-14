#include <iostream>
#include <cstring>

int main() {


    

    std::string a;

    getline(std::cin, a);

    std::string b;

    getline(std::cin, b);

    int count{0};
    for (size_t i = 0; i < a.size(); i++)
    {
        if (b == a.substr(i, 5))
        {
            count++;
        }

    }
    
    std::cout << b << " is found " << count << " times." << std::endl;
}