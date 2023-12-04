#include "DataBase.h"
#include <iostream>
#include <sstream>
#include <array>

DataBase::DataBase(/* args */)
{
    loadData();
    
}

bool DataBase::validateAccount(std::string& userId, std::string& PIN, int& index)
{
    for (int i = 0; i < AccountList.size(); ++i)
    {
        if (AccountList[i].getId() == userId && AccountList[i].getPIN() == PIN)
        {
            index = i;
            return true;
        }    
    }
    return false;
}

void DataBase::loadData()
{
    std::fstream file;

    file.open("data.txt", std::ios::in);

    if (!file)
    {
        std::cerr << "Cannot Open Data Base File" << std::endl;
    }

    std::string line;
    std::stringstream ss;

    std::array<std::string,3> reader;
    int i{0};

    while (!file.eof())
    {
       
        std::getline(file, line);
        line.push_back(',');

        for (char ch : line)
        {
            if (ch == ',' )
            {
                ss >> reader[i];
                i++;
                ss.str("");
                ss.clear();
            }

            if (ch != '$' && ch != ' ' && ch != ',')
            {
                ss << ch;
            }
        }

        double balanceReader = stod(reader[2]);
        Account* acc = new Account(reader[0], reader[1], balanceReader);
        AccountList.push_back(*acc);
        delete acc;
        i = 0;
    }
    file.close();

    

}

void DataBase::saveData()
{

    std::string line;
    std::stringstream ss;

    std::fstream file;
    
    file.open("data.txt", std::ios::out);

    if (!file)
    {
        std::cerr << "Cannot Open Data Base File" << std::endl;
    }

    for (int i = 0; i < AccountList.size(); ++i)
    {
        file << AccountList[i].getId();
        file << ", ";
        file << AccountList[i].getPIN();
        file << ", $";
        file << std::to_string(AccountList[i].getBalance());
        if (i != AccountList.size() - 1)
        {
            file << "\n"; 
        }
        
              
    }
    

    file.close();

}

double DataBase::getBalanceByIndex(int index)
{
    return AccountList[index].getBalance();
}

void DataBase::withdrawByIndex(int index, unsigned int amount)
{
    AccountList[index].withdraw(amount);
}

void DataBase::depositByIndex(int index, unsigned int amount)
{
    AccountList[index].deposit(amount);
}