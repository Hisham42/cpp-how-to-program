#include "quad.h"
#include <iostream>
#include <sstream>
#include <cmath>


Quad::Quad(double a, double b, double c, char variable) {
    setValues(a, b, c, variable);
}

Quad::~Quad() {
}

void Quad::setValues(double a, double b, double c, char variable) {
    setA(a);
    setB(b);
    setC(c);
    setVariable(variable);
}

void Quad::setA(double a) {
    if (a < 0)
    {
        this->a = 1;
    }
    else
    {
        this->a = a;
    } 
}

void Quad::setB(double b) {
   
    this->b = b;
    
}

void Quad::setC(double c) {
   
    this->c = c;
    
}

void Quad::setVariable(char variable) {
    this->variable = variable;    
}

void Quad::add(Quad first) {
    if (first.variable == variable)
    {
        a += first.a;
        b += first.b;
        c += first.c;
    }
    
}

void Quad::subtract(Quad first) {
    if (first.variable == variable)
    {
        a -= first.a;
        b -= first.b;
        c -= first.c;
    }

}

void Quad::tostring() {
    std::cout << a << variable << "^2 + " <<  b << variable << " + " << c << std::endl;
}

void Quad::solve() {
    root1 = (-b + (sqrt(pow(b, 2)-4*a*c))) / (2*a);
    root2 = (-b - (sqrt(pow(b, 2)-4*a*c))) / (2*a);

    if ((pow(b, 2) - 4*a*c) > 0)
    {
        std::cout << root1 << std::endl;
        std::cout << root2 << std::endl;
    }
    else
    {
        std::cout << "No Real Roots." << std::endl;
    }
    
}

void Quad::getA() {
    std::cout << a << std::endl;
}

void Quad::getB() {
    std::cout << b << std::endl;
}

void Quad::getC() {
    std::cout << c << std::endl;
}

void Quad::getVariable() {
    std::cout << variable << std::endl;
}

Quad Quad::operator+(const Quad& quad2) const {

    Quad temp;
    if (this->variable != quad2.variable)
    {
        throw std::invalid_argument("Different variables.");
    }

    temp.setA(this->a + quad2.a);
    temp.setB(this->b + quad2.b);
    temp.setC(this->c + quad2.c);

    return temp;
    

}

Quad Quad::operator-(const Quad& quad2) const {

    Quad temp;
    if (this->variable != quad2.variable)
    {
        throw std::invalid_argument("Different variables.");
    }

    temp.setA(this->a - quad2.a);
    temp.setB(this->b - quad2.b);
    temp.setC(this->c - quad2.c);

    return temp;
    

}

std::ostream& operator<<(std::ostream& a, const Quad& qua) {

    a << qua.a << "x^2 + ";
    a << qua.b << "b + " << qua.c << " = 0";

    return a;

}