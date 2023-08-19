#include "vicoba.h"


double Vicoba::annualInterestRate = 0.05;

/*Loan Amount, Loan Duration*/
Vicoba::Vicoba(unsigned int lAmount, unsigned int lDuration)
:loanAmount(lAmount), loanDuration(lDuration)
{
    
}

Vicoba::~Vicoba()
{
}

void Vicoba::setAnnualInterestRate(double a)
{
    annualInterestRate = a/100;
}

double Vicoba::getAnnualInterestRate() const
{
    return annualInterestRate;
}


void Vicoba::setLoanAmount(unsigned int a)
{
    loanAmount = a;
}

unsigned int Vicoba::getLoanAmount() const
{
    return loanAmount;
}

void Vicoba::setLoanDuration(unsigned int b)
{
    loanDuration = b;
}

unsigned int Vicoba::getLoanDuration() const
{
    return loanDuration;
}


double Vicoba::getToBePaid() const
{
    double a = loanAmount * annualInterestRate * loanDuration;
    cout << fixed << setprecision(2) << (loanAmount + a)
    << " should be paid within " << loanDuration << " years." << endl;
    return a + loanAmount;
}

double Vicoba::getToBePaidMonthly() const
{
    double a = loanAmount * annualInterestRate * loanDuration;
    cout << fixed << setprecision(2) << ((a + loanAmount) / loanDuration / 12) 
    << " should be paid monthly." << endl;

    return (a + loanAmount) / loanDuration / 12;
}



