#ifndef SAVINGACCOUNT_H
#define SAVINGACCOUNT_H

#include "account.h"

class SavingAccount : public Account
{
private:
    double interestRate;
public:
    SavingAccount(double=0, double=0);
    ~SavingAccount();

    void setInterestRate(double);

    double calculateInterest() override;

};




#endif