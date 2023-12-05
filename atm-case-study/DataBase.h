#ifndef DataBase_H
#define DataBase_H

#include <fstream>
#include "Account.h"
#include <vector>

class Screen;

class DataBase
{
private:
    
    std::vector<Account> AccountList; // vector to read data from the data base

    void loadData(); // load the data into the vector
    
    
public:
    DataBase(); // constructor

    bool validateAccount(std::string& userId, std::string& PIN, int& index); // calidate account and get its index in the vector
    void saveData(); // save data from the vector to the file

    double getBalanceByIndex(int index); // get balance

    void withdrawByIndex(int index, unsigned int amount); // withdraw money
    void depositByIndex(int index, unsigned int amount); // deposit money

};



#endif