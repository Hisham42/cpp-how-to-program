#ifndef Account_H
#define Account_H

#include <fstream>

class Account
{
private:
    
    std::string id;
    std::string PIN;
    double balance;
    
public:
    Account(std::string userId, std::string userPIN, double userBalance);

    std::string getId() const;

    std::string getPIN() const;
    
    double getBalance() const;

    void withdraw(double amount);

    void deposit(double amount);
      
};



#endif