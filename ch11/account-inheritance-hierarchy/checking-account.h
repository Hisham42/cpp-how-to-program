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
    void credit(double);
    void debit(double);

};




#endif