#ifndef TERM_H
#define TERM_H
#include "poly.h"

#include <iostream>

class Poly;

class Term
{
private:
    /* data */
    int coefficient;
    int exponenet;

    bool checked{false};
    
public:
    Term(const int&, const int&);
    Term(const Term*);
    Term();
    ~Term();


    int getC();
    int getE();
    bool getStatus();
    void setStatus(bool a);
    void setC(int a);
    void setE(int a);

    bool isIn(Poly&);

};


#endif