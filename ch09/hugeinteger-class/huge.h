#include <string>

#ifndef HUGE_CPP
#define HUGE_CPP



class Huge
{
private:
    
    std::string stringStorage;
    int numberStorage[40];
    bool Negative{false};
    
    
    void setString(std::string intt);
    void setNumber(int* num);
    void setNegative(bool neg);
    


public:
    Huge(std::string integ);
    ~Huge();

    void input(std::string intt);
    void output();
    void add(Huge bigInt2);
    void subtract(Huge bigInt2);
    bool isEqualTo(Huge bigInt2);
    bool isNotEqualTo(Huge bigInt2);
    bool isGreaterThan(Huge bigInt2);
    bool isGreaterThanOrEqualTo(Huge bigInt2);
    bool isLessThanOrEqualTo(Huge bigInt2);
};



#endif