#include <iostream>
#include <vector>
#include <array>
using namespace std;



#ifndef INTEGERSET_H
#define INTEGERSET_H

const int ARRAYSIZE = 100;

class Integerset
{
private:

    vector<int> setOfInts;
    
    
public:
    Integerset(vector<int>);
    Integerset(int*);
    
    Integerset();
    ~Integerset();

    void insertInt(int);
    

    void printInts();
    bool contains(int a);


    Integerset unionThis(Integerset);

    Integerset IntersectThis(Integerset);
    bool isEqualTo(Integerset);

};






#endif