#ifndef DOUBLESUBSCRIPT_H
#define DOUBLESUBSCRIPT_H

#include <ostream>

class DoubleSubscript
{

    friend std::ostream& operator<<(std::ostream&, const DoubleSubscript&);

private:
    int* ptrr;
    int col;

public:

    DoubleSubscript(int*, int);


    int operator[](int);

    
    

    ~DoubleSubscript();



};





#endif