#include <iostream>
#include "List.h"

int main() {

   

    List a('a');
    a.insertChar('b');
    a.insertChar('c');
    a.insertChar('d');
    a.insertChar('e');
    a.print();

    List b('f');
    b.insertChar('g');
    b.insertChar('h');
    b.insertChar('i');
    b.insertChar('j');
    b.print();



    
    

    List c = concatenate(a, b);
    c.print();



    List d = split(4, c);

    c.print();

    d.print();


    List e = reverse(d);

    e.print();
    
    
}