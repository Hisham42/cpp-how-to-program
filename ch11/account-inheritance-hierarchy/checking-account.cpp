#include "checking-account.h"

CheckingAccount::CheckingAccount(double ib, double fa)
: Account::Account(ib)
{
    setFeeAmount(fa);
}

CheckingAccount::~CheckingAccount()
{
}

void CheckingAccount::setFeeAmount(double f) {
    feeAmount = f;
}

void CheckingAccount::credit(double a) {

    if (Account::credit(a))
    {
        
        Account::debit(feeAmount);
    }
    
}

void CheckingAccount::debit(double a) {
 
    if (Account::debit(a))
    {
        if (!Account::debit(feeAmount))
        {
            Account::credit(a);
            cout << "no balance to pay feeAmount" << endl;
        } 
    }
    
}