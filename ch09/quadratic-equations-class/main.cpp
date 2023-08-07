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

    one.solve();

    Quad three(3, -6, 3);
    three.tostring();
    
    three.solve();

}