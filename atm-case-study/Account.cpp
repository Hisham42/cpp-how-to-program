#include "Account.h"

Account::Account(std::string userId, std::string userPIN, double userBalance)
{
    id = userId;
    PIN = userPIN;
    balance = userBalance;
}

std::string Account::getId() const
{
    return id;
}

std::string  Account::getPIN() const
{
    return PIN;
}

double Account::getBalance() const
{
    return balance;
}

void Account::withdraw(double amount) 
{
    balance -= amount;
}

void Account::deposit(double amount)
{
    balance += amount;
}
