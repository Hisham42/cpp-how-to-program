#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>

int main(int argc, char* argv[]) {

    if (argc > 1) {

        for (size_t i = 1; i < argc; i++)
        {
            if (tolower(argv[i][0]) == 'a')
            {
                std::cout << argv[i] << std::endl;
            }
            
        }

        std::cout << argc << std::endl;

    }
   
}