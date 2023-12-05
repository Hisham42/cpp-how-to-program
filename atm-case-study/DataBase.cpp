#include "DataBase.h"
#include <iostream>
#include <sstream>
#include <array>

DataBase::DataBase(/* args */)
{
    // load the data from the file when running the data base
    loadData();
}


// validate account using its id and pin and update its index
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

// load data from the file
void DataBase::loadData()
{
    std::fstream file; // create a file stream

    file.open("data.txt", std::ios::in); // open it

    if (!file) // check if file doesnot exist 
    {
        std::cerr << "Cannot Open Data Base File" << std::endl;
    }

    // create a string, string stream and a reader array
    std::string line; 
    std::stringstream ss;


    std::array<std::string,3> reader;
    int i{0};

    while (!file.eof()) // while you can read from data base
    {
       
        std::getline(file, line); // read line
        line.push_back(','); // inser , at its end

        for (char ch : line) // then use string stream to get data from the line and assign it to the array
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

        // then convert the balance to a double and create an account using id, PIN and balance that you red from the file
        double balanceReader = stod(reader[2]);
        Account* acc = new Account(reader[0], reader[1], balanceReader);
        AccountList.push_back(*acc);
        delete acc; // free the account that you create
        i = 0;
    }
    file.close(); // close the file to avoid leak
}

// save data reads the Account list vector and override the file
void DataBase::saveData()
{

    std::string line;
    std::stringstream ss;

    std::fstream file;
    
    file.open("data.txt", std::ios::out); // open file as output

    if (!file) // check exitence
    {
        std::cerr << "Cannot Open Data Base File" << std::endl;
    }

    // create a file from the account list vector
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
    

    file.close(); // close file

}

// get account balance using index
double DataBase::getBalanceByIndex(int index)
{
    return AccountList[index].getBalance();
}

// withdraw from account using index
void DataBase::withdrawByIndex(int index, unsigned int amount)
{
    AccountList[index].withdraw(amount);
}

// deposit using index
void DataBase::depositByIndex(int index, unsigned int amount)
{
    AccountList[index].deposit(amount);
}