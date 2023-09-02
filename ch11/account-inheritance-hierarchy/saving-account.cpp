#include "saving-account.h"

SavingAccount::SavingAccount(double ib, double ir)
: Account::Account(ib)
{
    setInterestRate(ir);
}

SavingAccount::~SavingAccount()
{
}

void SavingAccount::setInterestRate(double f) {
    interestRate = f;
}

double SavingAccount::calculateInterest() {

    return interestRate * Account::getBalance();
}