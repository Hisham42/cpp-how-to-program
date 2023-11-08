#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


void printHelper(std::string& a, std::string::iterator it) {
    if (it != a.end())
    {
        printHelper(a, it + 1);
        std::cout << *it;
    }
    
}

void print(std::string& ss) {
    std::string::iterator itera = ss.begin();
    printHelper(ss, itera);
}


int main() {

    std::string a;

    getline(std::cin, a);

    for (auto i = a.rbegin(); i != a.rend(); i++)
    {
        std::cout << *i;
    }
    std::cout << std::endl;

    // ///////////////////

    std::string b;

    getline(std::cin, b);

    print(b);

    std::cout << std::endl;
    

}