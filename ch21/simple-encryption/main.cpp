#include <iostream>
#include <string>
#include <sstream>

std::string encrypt(std::string input) {

    std::stringstream userIn{""};
    std::string retur;

    for (auto i = input.begin(); i != input.end(); i++)
    {
        userIn << char(*i + 13);
    }

    userIn >> retur;
    return retur;

    
}

std::string decrypt(std::string input) {

    std::stringstream userIn{""};
    std::string retur;

    for (auto i = input.begin(); i != input.end(); i++)
    {
        userIn << char(*i - 13);
    }

    userIn >> retur;
    return retur;

    
}

int main() {
    std::string input;
    std::cout << "Please Enter a String" << std::endl;

    std::cin >> input;

    std::cout << encrypt(input) << std::endl;

    std::cout << decrypt(encrypt(input)) << std::endl;

}