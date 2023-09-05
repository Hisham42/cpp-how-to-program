#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
using namespace std;

class Account
{
private:
    double balance; // account balance
    void setBalance(double); // balance setter

public:
    Account(double=0);
    virtual ~Account();

    double getBalance() const; // balance getter
    virtual bool credit(double);
    virtual bool debit(double);

    virtual double calculateInterest() = 0;


};


#endif