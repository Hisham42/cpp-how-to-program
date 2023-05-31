// Account class with name and balance data members, and a 
// constructor and deposit function that each perform validation.
#include <string>
#include <iostream>

class Account {

private:
   unsigned int accountNumber;
   std::string firstName;
   std::string lastName;
   double balance;


public:
   // Account constructor with two parameters  
   Account(unsigned int inAccountNumber, std::string inFirstName, std::string inLastName, double inBalance)
      : accountNumber{inAccountNumber}, firstName{inFirstName}, lastName{inLastName}, balance{inBalance} 
      { //
   }

   void displayAccount() {
    std::cout << "Account Number: " << accountNumber << "\n";

    std::cout << "First Name: " << firstName << "\n";

    std::cout << "Last Name: " << lastName << "\n";

    std::cout << "Balance: " << balance << "\n";

   }
}; // end class Account


