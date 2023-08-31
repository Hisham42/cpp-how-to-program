#include "poly.h"

int main() {
    Term t1(5,0);
    Term t2(4,1);
    Term t3(4,2);
    

    Term t6(10,0);
    Term t7(4,1);
    Term t8(3,5);
    
    




    Poly p1({t1, t2, t3});
    
    Poly p2({t6, t7, t8});

    Poly p3, p4, p5;

    p5 = (p1 + p2);

    cout << p5 << endl;

    p1+= p2;

    cout << p1 << endl;
    cout << p4 << endl;
    






    
}