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

void decryptUsing(std::string input) {

    char common[] = {'a', 'e', 'o', 'i', 'u', 's', 't', 'r'};

    for (size_t i = 0; i < input.size(); i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
        
            char key = input[i] - common[j];
            
            std::stringstream userIn{""};
            std::string retur;

            for (auto i = input.begin(); i != input.end(); i++)
            {
                userIn << char(*i - key);
            }

            userIn >> retur;

            std::cout << retur << std::endl;

        }
        

    }
}

int main() {
    std::string input;
    std::cout << "Please Enter a String" << std::endl;

    std::cin >> input;

    std::cout << encrypt(input) << std::endl;

    decryptUsing(encrypt(input));
}