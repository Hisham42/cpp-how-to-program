#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Client
{

    friend ostream& operator<<(ostream&, Client&);
    friend istream& operator>>(istream&, Client&);


private:
    char name[20];
    char country[20];
    char telephoneNumber[20];
    double balance;
    int accountNumber;
    

public:
    Client(int=0, const string& = "", const string& ="", const string& ="", double=0);
    ~Client();

    // setters

    void setAccountNumber(int);
    void setName(const string&);
    void setPhone(const string&);
    void setCountry(const string&);
    void setBalance(double);

    // getters

    int getAccountNumber() const;
    string getName() const;
    string getPhone() const;
    string getCountry() const;
    double getBalance() const;

};

#endif