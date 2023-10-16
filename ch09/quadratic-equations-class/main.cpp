#include <iostream>
#include "quad.h"
using namespace std;

int main(){

   
    Quad one;

    Quad two(2, -6, -9);

    one.add(two);

    one.tostring();
    one.getA();
    one.getB();
    one.getC();

    try
    {
        one.solve();
    }
    catch(const NoRealRootException& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    Quad three(3, -6, 3);
    three.tostring();
    
    try
    {
        three.solve();
    }
    catch(const std::runtime_error& e)
    {
        
        std::cerr << e.what() << '\n';
    }

}