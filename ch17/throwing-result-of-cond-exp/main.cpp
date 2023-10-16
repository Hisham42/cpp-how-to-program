#include <iostream>



int main() {
    double x{0};

    std::cin >> x;

    try
    {
        if (typeid(x) == typeid(int))
        {
            throw 101;
        }
        else if (typeid(x) == typeid(double))
        {
            throw 5.5;
        }
        
         
        
    }
    catch(int e)
    {
        std::cerr << "this is int " << e << '\n';
    }

    catch(double d)
    {
        std::cerr << "this is double " << d << '\n';
    }
    
    






}