#ifndef QUAD_H
#define QUAD_H

#include <sstream>

class Quad
{

    friend std::ostream& operator<<(std::ostream&, const Quad&);

private:
    /* data */
    double a, b, c, root1, root2;
    char variable;



public:

    Quad operator+(const Quad&) const;
    Quad operator-(const Quad&) const;
    
   

    Quad(double q=1, double w=0, double e=0, char r='x'); //constructor

    //setters
    void setValues(double, double, double, char);
    void setA(double);
    void setB(double);
    void setC(double);
    void setVariable(char);

    


    //getters
    void getA();
    void getB();
    void getC();
    void getVariable();


    //members
    void add(Quad);
    void subtract(Quad);
    void tostring();
    void solve();
    ~Quad(); //destructor
};


#endif
