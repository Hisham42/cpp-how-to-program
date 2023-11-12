#include <iostream>
#include <cstring>

int main(int argc, char* argv[]) {

    if (argc > 1)
    {
        std::cout << argv[1] << " " << argv[2] <<  " " << argv[3] << " " << argv[4] << std::endl;


        for (size_t j = 1; j <= 4; j++)
        {
            double value{0};

            
            value = atof(argv[j]);
            std::cout << value << " ";
            
            
        
        }
        std::cout << std::endl;
    

    
    
    
    
    
    
    
    
    
    
    
    
    
    }    
}