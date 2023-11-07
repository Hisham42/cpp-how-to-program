#include <iostream>
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
    std::string a{""};
    std::stringstream ss{""};

    getline(std::cin, a);

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
        

        if (*i != ' ' && !isIn(i, ss))
        {
            std::cout << *i << ": " << num << std::endl;
            ss << char(*i);
        }
        
    }
    
    
}