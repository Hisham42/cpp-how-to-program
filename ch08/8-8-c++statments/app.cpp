#include <iostream>
#include <array>

using namespace std;

int main() {
    
    int size = 5;
    long bigIntegers[size];


    long *Ptr{nullptr};

    *Ptr = *(bigIntegers + 3);

    zero(bigIntegers, &size);

}

void zero(long *big, int *sizePtr) {




}