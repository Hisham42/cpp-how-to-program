#include <iostream>

/*
a) Account number (an integer)
b) Balance at the beginning of the month
c) Total of all items charged by this customer this month
d) Total of all credits applied to this customer's account this month
e) Allowed credit limit*/
class Account
{
private:
    /* data */
    unsigned int accountNumber;
    float balance;
    float totalCharges;
    float creditApplied;
    float creditLimit;

public:

    Account(unsigned int inAccountNumber, float inBalance, float inTotalCharges,
        float inCreditApplied, float inCreditLimit) : accountNumber{inAccountNumber},
        balance{inBalance}, totalCharges{inTotalCharges}, creditApplied{inCreditApplied},
        creditLimit{inCreditLimit} {
            if (accountNumber < 0)
            {
                accountNumber = 0;
            }
            if (balance < 0)
            {
                balance = 0;
            }
            if (totalCharges < 0)
            {
                totalCharges = 0;
            }
            if (creditApplied < 0)
            {
                creditApplied = 0;
            }
            if (creditLimit < 0)
            {
                creditLimit = 0;
            }
            
        }
//setters
    void setAccountNumber(float x){
        accountNumber = x;
    }

    void setBalance(float y){
        balance = y;
    }

    void setTotalCharges(float z){
        totalCharges = z;
    }

    void setCreditApplied(float a){
        creditApplied = a;
    }

    void setCreditLimit(float b){
        creditLimit = b;
    }
//getters

    unsigned int getAccountNumber(){
        return accountNumber;
    }
    float getBalance(){
        float newBalance = balance + totalCharges - creditApplied;
        return newBalance;
    }
    float getTotalCharges(){
        return totalCharges;
    }
    float getCreditApplied(){
        return creditApplied;
    }
    float getCreditLimit(){
        return creditLimit;
    }
};


