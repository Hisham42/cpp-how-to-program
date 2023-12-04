#ifndef DataBase_H
#define DataBase_H

#include <fstream>
#include "Account.h"
#include <vector>

class Screen;

class DataBase
{
private:
    
    std::vector<Account> AccountList;

    void loadData();
    
    
public:
    DataBase(/* args */);

    bool validateAccount(std::string& userId, std::string& PIN, int& index);
    void saveData();

    double getBalanceByIndex(int index);

    void withdrawByIndex(int index, unsigned int amount);
    void depositByIndex(int index, unsigned int amount);

};



#endif