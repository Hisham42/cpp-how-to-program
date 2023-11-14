#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>


int countStr(std::fstream& file, const std::string& b)
{
    std::string s;
    std::stringstream ss;
    char a;

    while (!file.eof())
    {
        file >> a;
        ss << a;
    }


    ss >> s;
    


    int count{0};
    for (size_t i = 0; i < s.size(); i++)
    {
        if (b == s.substr(i, b.size()))
        {
            count++;
        }

    }

    return count;
    
}

int main() {

    std::fstream file("file.txt", std::ios::in);

    if (!file)
    {
        std::cout << "Cannot open File" << std::endl;
    }
    
    std::cout << countStr(file, "our") << std::endl;

    file.close();
}