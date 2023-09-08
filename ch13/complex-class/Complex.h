#ifndef COMPLEX_H
#define COMPLEX_H


#include <iostream>
#include <iomanip>

using namespace std;




class Complex
{

    friend ostream& operator<<(ostream&, Complex&);
    friend istream& operator>>(istream&, Complex&);

private:
    int real, imaginary;
    char sign;

public:
    Complex(/* args */);
    ~Complex();
};



#endif