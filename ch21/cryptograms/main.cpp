#include <iostream>
#include <string>
#include <sstream>
#include <vector>

std::string encrypt(std::string input) {

    int j = 0;

    std::string encrypted{input};
    
    for (auto i = input.begin(); i != input.end(); i++, j++)
    {
        if (*i == ' ')
        {
            encrypted[j] = ' ';
        }
        
        else
        {
            encrypted[j] = char(*i + input.size() - 26);
        }
    }

    return encrypted;

}

std::string decrypt(std::string input) {

    int j = 0;
    std::string decrypted{input};

    
    for (auto i = input.begin(); i != input.end(); i++, j++)
    {
        if (*i == ' ')
        {
            decrypted[j] = ' ';
        }
       
        else
        {
            decrypted[j] = char(*i - input.size() + 26);
        }
    }

    return decrypted;
}

int main() {
    std::string input;
    std::cout << "Please Enter a String" << std::endl;

    getline(std::cin, input);


    std::cout << encrypt(input) << std::endl;

    char in;

    std::string temp{input};

    int spaces{0};
    for (auto i = temp.begin(); i != temp.end(); i++)
    {
        if (*i == ' ')
        {
            spaces++;
        }
        else
        {
            *i = '*';
        }
        
    }
    
    int num = spaces;
    while (num != temp.size())
    {
        std::cin >> in;
        for (size_t i = 0; i < temp.size(); i++)
        {
            if (encrypt(input)[i] == ' ')
            {
                std::cout << ' ';
            }
            else if (encrypt(input)[i] == in)
            {
                temp[i] = in;
                std::cout << temp[i];
                num++;
            }
            else
            {
                std::cout << temp[i];
            }
        }

        std::cout << std::endl;
    }
    
    
    

}