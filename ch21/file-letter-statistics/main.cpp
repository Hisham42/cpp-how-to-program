#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


bool isIn(std::string::iterator& iter, std::stringstream& b) {
    std::string a = b.str();

    for (auto i = a.begin(); i != a.end(); i++)
    {
        if (*iter == *i && *iter !=' ')
        {
            return true;
        }
        
    }

    return false;
}

int main() {

    std::fstream file;

    file.open("paragraph.txt", std::ios::out | std::ios::in);

    if (!file.is_open())
    {
        std::cerr << "Cannot open file!" << std::endl;
    }
    
    std::string a{""};

    std::stringstream ss{""};

    char b{'\0'};


    while (file)
    {   
        file >> b;
        if (std::isalpha(b) && b !=' ')
        {
            a.push_back(b);
        }
    }

    for (auto i = a.begin(); i != a.end(); i++)
    {
        int num{0};

        for (auto j = a.begin(); j != a.end(); j++)
        {
            if (*i == *j)
            {
                num++;
            }
        }
        

        if (!isIn(i, ss))
        {
            std::cout << *i << ": ";

            for (size_t s = 0; s < num; s++)
            {
                std::cout << "*" ;
            }

            std::cout << std::endl;
            
            
            ss << char(*i);
        }
        
    }
    
    
}