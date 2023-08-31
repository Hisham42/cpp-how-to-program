#ifndef POLY_H
#define POLY_H

#include <iostream>
#include <sstream>
#include <initializer_list>

#include "term.h"

using namespace std;

class Term;

class Poly
{

friend ostream& operator<<(ostream&, const Poly&);
friend Poly reformulatePoly(const Poly&);


private:
    /* data */
    int arraySize;
    Term** ptr;

public:
    Poly(initializer_list<Term> list);
    Poly(int=1);
    ~Poly();

    Term getPtr(int&) const;

    Poly operator+(const Poly&) const;

    Poly operator-(const Poly&) const;

    Poly operator*(const Poly&) const;
    
    void operator=(const Poly&) ;
    int getSize() const;

    int expectedSize(const Poly&) const;

    void operator*=(const Poly&);
    void operator-=(const Poly&);
    void operator+=(const Poly&);

    bool isZero() const;

    


};








#endif