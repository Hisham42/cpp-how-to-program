#include <iostream>
#include "List.h"

int main() {

   

    List<char> a('a');
    a.insertChar('b');
    a.insertChar('c');
    a.insertChar('d');
    a.insertChar('e');
    a.print();

    List<char> b('f');
    b.insertChar('g');
    b.insertChar('h');
    b.insertChar('i');
    b.insertChar('j');
    b.print();
    b.recPrint();



    
    

    
    
}