#include <iostream>
#include "List.h"

int main() {

    List<char> b('f');
    b.insert('g');
    b.insert('h');
    b.insert('i');
    b.insert('j');

    b.print();
    

    b.inserAt(2, 'z');
    
    b.print();

    b.deleteAt(3);

    b.insertAtBack('a');
    
    b.insertAtBack('a');

    b.print();
    
}