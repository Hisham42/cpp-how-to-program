#ifndef DS_ARRAY_H
#define DS_ARRAY_H

#include <iostream>
#include "doublesubscript.h"
#include <initializer_list>

class DsArray
{
    friend std::istream& operator>>(std::istream&, DsArray&);
    friend std::ostream& operator<<(std::ostream&, const DsArray&);

private:
    /* data */
    int rows;
    int columns;
    int** ptr;

public:
    DsArray(int, int);



    DsArray(int);

    
    ~DsArray();

    int& operator()(int, int) const;

    void operator()(std::initializer_list<int>);

    DoubleSubscript operator[](int) ;

    bool operator==(DsArray&) const;

    bool operator!=(DsArray&) const;



};


#endif