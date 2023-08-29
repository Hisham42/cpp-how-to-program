#include <iostream>
#include "quad.h"
using namespace std;

int main(){

   
    Quad one;

    Quad two(2, -6, -9);

    Quad three(2, -6, -9);

    one.add(two);

    one.tostring();
    one.getA();
    one.getB();
    one.getC();

    one.solve();


    three.tostring();
    
    three.solve();

    
    cout << two << endl;
    cout << three + two << endl;

}