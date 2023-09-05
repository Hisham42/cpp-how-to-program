#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "account.h"

class CheckingAccount : public Account
{
private:
    double feeAmount;
public:
    CheckingAccount(double=0, double=0);
    ~CheckingAccount();

    void setFeeAmount(double);
    bool credit(double) override ;
    bool debit(double) override;

    double calculateInterest() override;

};




#endif