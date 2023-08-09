#include <string>

#ifndef RATIONAL_H
#define RATIONAL_H

class Rational
{
private:
    int numerator, denominator;

public:
    Rational(int numerator=1, int denominator=1); //constractor
    ~Rational(); //destractor

    void setFraction(int numerator, int denominator);

    void getFraction();

    void add(Rational x);
    void subtract(Rational x);
    void multiply(Rational x);
    void divide(Rational x);

    std::string toRationalString();

    double toDouble();
    

};

#endif