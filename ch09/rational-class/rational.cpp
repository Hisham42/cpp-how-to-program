#include <iostream>


#include "rational.h"

Rational::Rational(int num, int den)
{
    setFraction(num, den);

}

Rational::~Rational()
{
}


void Rational::setFraction(int num, int den)
{

    numerator = num;
    denominator = den;

    if (num < den)
    {
        int i{2};
        while (i <= numerator)
        {
            if (numerator % i == 0 && denominator % i == 0)
            {
                numerator /= i;
                denominator /= i;
            }
            i++;
        }
    }
    else if (num == den)
    {
        numerator = 1;
        denominator = 1;
    }
    else
    {
        int j{2};
        while (j <= denominator)
        {
            if (numerator % j == 0 && denominator % j == 0)
            {
                numerator /= j;
                denominator /= j;
            }
            j++;
           
            
        }
    }
    
    
    
    
}

void Rational::getFraction()
{
    std::cout << "Fraction is " << numerator << "/" << denominator << std::endl;
    
}

void Rational::add(Rational x)
{

    if (denominator != x.denominator)
    {
        int helper = x.denominator;

        x.denominator = denominator * x.denominator;
        x.numerator = denominator * x.numerator;

        denominator = helper * denominator;
        this->numerator = helper * numerator;

        numerator += x.numerator;
    }
    else
    {
        numerator += x.numerator;
        setFraction(numerator, denominator);
    }
    
}


void Rational::subtract(Rational x)
{

    if (denominator != x.denominator)
    {
        int helper = x.denominator;

        x.denominator = denominator * x.denominator;
        x.numerator = denominator * x.numerator;

        denominator = helper * denominator;
        this->numerator = helper * numerator;

        numerator -= x.numerator;
    }
    else
    {
        numerator -= x.numerator;
        setFraction(numerator, denominator);
    }
    
}

void Rational::multiply(Rational x)
{

    numerator *= x.numerator;
    denominator *= x.denominator;
    setFraction(numerator, denominator);
    
}

void Rational::divide(Rational x)
{

    numerator *= x.denominator;
    denominator *= x.numerator;
    setFraction(numerator, denominator);
    
}

std::string Rational::toRationalString()
{
    std::string a = std::to_string(numerator);
    std::string b = std::to_string(denominator);

    std::string fraction =  a + "/" + b;
    return fraction;
}

double Rational::toDouble()
{
    double a = numerator * 1.0;
    double b = denominator * 1.0;

    return a/b;
}

