#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>

int main(int argc, char* argv[]) {

    if (argc > 1) {

        for (size_t i = 1; i < argc; i++)
        {
            if (strstr(argv[i], "ed.\0") != nullptr)
            {
                std::cout << argv[i] << std::endl;
            }
            
        }

    }
   
}