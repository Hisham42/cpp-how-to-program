#include <iostream>

#include "DoubleList.h"

int main() {
    DoubleList<char> a('a');
    a.insert('b');
    a.insert('c');
    a.print();

    DoubleList b = reverse(a);
    b.print();
}