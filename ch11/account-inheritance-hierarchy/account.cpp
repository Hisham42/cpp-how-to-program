#include "account.h"

Account::Account(double b)
{
    setBalance(b);
}

Account::~Account()
{
}

void Account::setBalance(double b) {
    if (b < 0)
    {
        balance = 0;
        cout << "Initial Balance was invalid." << endl;
    }
    balance = b;
    
}

double Account::getBalance() const {
    
    return balance;    
}

bool Account::credit(double b) {

    if (b > 0 || b == 0)
    {
        balance += b;
        return true;
    }
    else
    {
        cout << "Invalid credit amount." << endl;
        return false;
    }
    

   
    
}

bool Account::debit(double b) {

    if (b < balance || b == balance)
    {
        balance -= b;
        return true;
    }
    else
    {
        cout << "Debit amount exceeded account balance." << endl;
        return false;
    }
}