#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>

int countChr(std::fstream& file, char d) {
    int count{0};
    char a{char()};

    while (!file.eof())
    {
        file >> a;

        if (a == d)
        {
            count++;
        }
        
    }

    return count;

}

int main() {

    //input file

    std::fstream file("file.txt", std::ios::in);

    if (!file)
    {
        std::cout << "Cannot open File" << std::endl;
    }
    


    char a;
    int count = countChr(file, 'a');

    std::cout << count << std::endl;

}