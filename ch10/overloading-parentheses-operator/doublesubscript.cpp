#include <stdexcept>
#include "doublesubscript.h"
#include <iostream>


DoubleSubscript::DoubleSubscript(int* a, int c)
: ptrr(a), col(c)
{

}

DoubleSubscript::~DoubleSubscript()
{
}


int DoubleSubscript::operator[](int c)
{
    if (c >= col)
    {
        throw std::invalid_argument{"Invalid Array index"};
    }
    
    return ptrr[c];
}

std::ostream& operator<<(std::ostream& output, const DoubleSubscript& a)
{
    output << "Array output:" << std::endl;

    output << a.ptrr[a.col] << " ";

    return output;
    
}

