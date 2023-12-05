#include "Account.h"

//Account constructor
Account::Account(std::string userId, std::string userPIN, double userBalance)
{
    id = userId;
    PIN = userPIN;
    balance = userBalance;
}

//get Account ID
std::string Account::getId() const
{
    return id;
}

//get Account PIN
std::string  Account::getPIN() const
{
    return PIN;
}

//get Account Balance
double Account::getBalance() const
{
    return balance;
}

//withdraw amount from the account
void Account::withdraw(double amount) 
{
    balance -= amount;
}

//deposit amount to the account
void Account::deposit(double amount)
{
    balance += amount;
}
