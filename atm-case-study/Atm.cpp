#include "Atm.h"
#include <chrono>
#include <thread>


Atm::Atm(const std::string& bankName)
{
    BankName = bankName;
    customer.setStatus(false); //ensure to unathenticate user if program closed suddenly
}

//main function for the progrram
void Atm::run(/* args */)
{
    // display welcome message and get user id and PIN
    while (true)
    {
        screen.displayMessage("Welcome to " + BankName + "!\nPlease enter your account number: "); 
        std::string userId = keypad.getInput(); 
        screen.displayMessage("Please enter your PIN: "); 
        std::string PIN = keypad.getInput();

        //authenticate the user and return his index in the vector database
        int index = authenticateUser(userId, PIN);

        //if the user is verified
        if (customer.getStatus())
        {
            /* userAuthenticated */

            //create enum class for user choices
            enum class Choice : int {
                ViewMyBalance = 1,
                WithdrawCash,
                DepositFunds,
                Exit
            };

            //create enum class for withdraw section
            enum class WithdrawChoice : int {
                $20 = 1,
                $40,
                $60,
                $100,
                $200,
                CancelTransaction
            };
            unsigned int amount{0};
            Choice userChoice;
            WithdrawChoice userWithdrawChoice;
            

            std::string userDepositChoice;
            unsigned int userDepositAmount;

            //while user didnot choose exit proceed with the following
            while ( userChoice != Choice::Exit )    
            {
                //display main menu and take user input
                screen.displayMainMenu();
                userChoice = static_cast<Choice>(stoi(keypad.getInput()));

                //based on the choice perform a task
                switch (userChoice)
                {
                //view balance
                case Choice::ViewMyBalance:
                    screen.displayMessage("Account Balance: $" + std::to_string(dataBase.getBalanceByIndex(index)));
                    std::this_thread::sleep_for(std::chrono::seconds(1));

                    break;

                //withdraw cash
                case Choice::WithdrawCash:
                    //display withdraw cash menu and take user input to perform task
                    screen.displayWithdrawMenu();
                    userWithdrawChoice = static_cast<WithdrawChoice>(stoi(keypad.getInput()));

                    //based on user choice perfrom a task
                    switch (userWithdrawChoice)
                    {
                    case WithdrawChoice::$20:
                        amount = 20;
                        if (cashDispenser.getAvailBills() > 0 && dataBase.getBalanceByIndex(index) > amount)
                        {
                            dataBase.withdrawByIndex(index, amount);
                        }
                        break;

                    case WithdrawChoice::$40:
                        amount = 40;
                        if (cashDispenser.getAvailBills() > 0 && dataBase.getBalanceByIndex(index) > amount)
                        {
                            dataBase.withdrawByIndex(index, amount);
                        }
                        break;

                    case WithdrawChoice::$60:
                        amount = 60;
                        if (cashDispenser.getAvailBills() > 0 && dataBase.getBalanceByIndex(index) > amount)
                        {
                            dataBase.withdrawByIndex(index, amount);
                        }
                        break;

                    case WithdrawChoice::$100:
                        amount = 100;
                        if (cashDispenser.getAvailBills() > 0 && dataBase.getBalanceByIndex(index) > amount)
                        {
                            dataBase.withdrawByIndex(index, amount);
                        }
                        break;

                    case WithdrawChoice::$200:
                        amount = 200;
                        if (cashDispenser.getAvailBills() > 0 && dataBase.getBalanceByIndex(index) > amount)
                        {
                            dataBase.withdrawByIndex(index, amount);
                        }
                        break;

                    case WithdrawChoice::CancelTransaction:
                        amount = 0;
                        break;
                    
                    default:
                        break;
                    }

                    // if user didnot enter valid choice so nothing happens
                    if (amount != 0)
                    {
                        excuteTransaction();
                        screen.displayMessage("Pick your $" + std::to_string(amount));
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                        cashDispenser.dispenseCash(amount);
                    }
                    break;

                //deposit menu
                case Choice::DepositFunds:

                    //display deposit menu and take user input
                    screen.displayMessage("Please Enter the amount: ");
                    userDepositChoice = keypad.getInput();
                    
                    //convert user input to unsigned int
                    userDepositAmount = stoul(userDepositChoice);

                    //check if deposit slot received Envelops and user deposted an amount > 0 and there is a space in the cash machine
                    if (
                        depositSlot.receiveEnvelops() &&
                        userDepositAmount > 0 && 
                        cashDispenser.getAvailBills() + userDepositAmount <= cashDispenser.MAX_CASH
                        )
                    {
                        //then deposit the amount to user account and add cash to the dispenser
                        dataBase.depositByIndex(index, userDepositAmount);
                        cashDispenser.addCash(userDepositAmount);
                        screen.displayMessage("You have deposited $" + std::to_string(userDepositAmount));
                        std::this_thread::sleep_for(std::chrono::seconds(1));


                    }
                    //else if user deposited too much money
                    else if (
                        depositSlot.receiveEnvelops() && 
                        userDepositAmount > 0 && 
                        cashDispenser.getAvailBills() + userDepositAmount > cashDispenser.MAX_CASH
                        )

                    {
                        //then the atm will take the amount it can and return the rest to the user
                        amount = cashDispenser.MAX_CASH - cashDispenser.getAvailBills();
                        screen.displayMessage("ATM is full, you have deposited $" + std::to_string(amount));
                        dataBase.depositByIndex(index, amount);
                        screen.displayMessage("Please receive back your $" + std::to_string(userDepositAmount - amount));
                        std::this_thread::sleep_for(std::chrono::seconds(1));

                    }
                    //in case of invalid input
                    else
                    {
                        screen.displayMessage("Invalid Amount");
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                    }
                    
                    excuteTransaction();
                    
                    break;

                //exit choice
                case Choice::Exit:
                    //make sure that the user is no longer authenticated
                    customer.~User();
                    break;
                
                default:
                    //in case of invalid input
                    screen.displayMessage("Invalid Input");
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                    
                }
                
            }

            //reset choice to make the program repeat itself
            userChoice = static_cast<Choice>(-1);
        }
        //if user is not authenticated
        else
        {
            screen.displayMessage("Invalid User or PIN\n-----------------------");
            std::this_thread::sleep_for(std::chrono::seconds(1));
            
        } 
    }
}
// this returns Account index if valid, if not returns -1
int Atm::authenticateUser(std::string& userId, std::string& PIN)
{
    int accountIndex = -1;
    //validate user and pin from data base and assign account index to locate the user in the vector
    if(dataBase.validateAccount(userId, PIN, accountIndex)) {
        customer.setStatus(true);
    }

    return accountIndex;

}

//save new changes to data base after excuting a transaction
void Atm::excuteTransaction(/* args */)
{

    dataBase.saveData();
}