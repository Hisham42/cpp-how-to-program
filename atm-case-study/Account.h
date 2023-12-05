#ifndef Account_H
#define Account_H

#include <fstream>

class Account
{
private:
    
    std::string id; //account id
    std::string PIN; //account pin
    double balance; //account balance
    
public:
    Account(std::string userId, std::string userPIN, double userBalance); //account constructor

    std::string getId() const; //get account id

    std::string getPIN() const; //get account PIN
    
    double getBalance() const; //get balance

    void withdraw(double amount); //withdraw amount

    void deposit(double amount); //deposit amount
      
};



#endif