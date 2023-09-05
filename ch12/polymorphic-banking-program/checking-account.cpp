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

bool CheckingAccount::credit(double a) {

    if (Account::credit(a))
    {
        
        Account::debit(feeAmount);
        return true;
    }
    else
    {
        return false;
    }
    
}

bool CheckingAccount::debit(double a) {
 
    if (Account::debit(a))
    {
        if (!Account::debit(feeAmount))
        {
            Account::credit(a);
            cout << "no balance to pay feeAmount" << endl;
            return false;
        }
        else
        {
            return true;
        }
        
    }
    else 
    {
        return false;
    }
    
}

double CheckingAccount::calculateInterest() {

    return 0;
}