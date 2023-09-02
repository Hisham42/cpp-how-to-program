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
    ~Account();

    
    double getBalance() const; // balance getter
    bool credit(double);
    bool debit(double);
};


#endif