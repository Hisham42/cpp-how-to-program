#include <iostream>
#include <string>
#include <iomanip>

using namespace std;



#ifndef VICOBA_H
#define VICOBA_H



class Vicoba
{
private:
    unsigned int loanAmount;
    
    unsigned int loanDuration;

    static double annualInterestRate;
    

public:

    explicit Vicoba(unsigned int, unsigned int);
    ~Vicoba();
    
    double getToBePaid() const;
    double getToBePaidMonthly() const;
    unsigned int getLoanAmount() const;
    unsigned int getLoanDuration() const;

    void setLoanDuration(unsigned int);
    void setLoanAmount(unsigned int);
    
    double getAnnualInterestRate() const;

    static void setAnnualInterestRate(double);

};

#endif