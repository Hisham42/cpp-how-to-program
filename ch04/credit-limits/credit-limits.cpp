/*
Develop a C++ program that will determine whether a department-store
customer has exceeded the credit limit on a charge account. For each customer, the following facts
are available:

a) Account number (an integer)
b) Balance at the beginning of the month
c) Total of all items charged by this customer this month
d) Total of all credits applied to this customer's account this month
e) Allowed credit limit
The program should use a while statement to input each of these facts, calculate the new balance
(= beginning balance + charges – credits) and determine whether the new balance exceeds the customer’s
credit limit. For those customers whose credit limit is exceeded, the program should display the cus-
tomer’s account number, credit limit, new balance and the message “Credit Limit Exceeded.”

*/


#include <iostream>
#include "credit-limits.h"
using namespace std;

int main(){

    unsigned int accountNumber;
    float balance;
    float totalCharges;
    float creditApplied;
    float creditLimit;


    


    while (accountNumber != -1)
    {
        cout << "\nEnter Account Number (or -1 to quit): ";
        cin >> accountNumber;

        if (accountNumber != -1)
        {    
            cout << "Enter beginning balance: ";
            cin >> balance;
            cout << "Enter total charges: ";
            cin >> totalCharges;
            cout << "Enter total credits: ";
            cin >> creditApplied;
            cout << "Enter credit limit: ";
            cin >> creditLimit;

            Account account(accountNumber, balance, totalCharges, creditApplied, creditLimit);
            cout << "New Balance is " << account.getBalance();

            if (account.getBalance() > creditLimit )
            {
                cout << "\nAccount:      " << account.getAccountNumber();
                cout << "\nCredit Limit: " << account.getCreditLimit();
                cout << "\nBalance:      " << account.getBalance();
                cout << "\nCredit Limit Exceeded.\n";
            }

        }   


    }
    
    





}