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

    
    concatenate(a, b);
}