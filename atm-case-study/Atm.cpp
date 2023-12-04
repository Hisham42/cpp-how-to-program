#include "Atm.h"
#include <chrono>
#include <thread>


Atm::Atm(const std::string& bankName)
{
    BankName = bankName;
}

void Atm::run(/* args */)
{

    screen.displayMessage("Welcome to " + BankName + "!\nPlease enter your account number: ");
    std::string userId = keypad.getInput();
    screen.displayMessage("Please enter your PIN: ");
    std::string PIN = keypad.getInput();

    int index = authenticateUser(userId, PIN);

    if (customer.getStatus())
    {
        /* userAuthenticated */

        

        enum class Choice : int {
            ViewMyBalance = 1,
            WithdrawCash,
            DepositFunds,
            Exit
        };

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

        while (
                
                userChoice != Choice::Exit 
            )
            
        {
            screen.displayMainMenu();
            userChoice = static_cast<Choice>(stoi(keypad.getInput()));

            switch (userChoice)
            {
            case Choice::ViewMyBalance:
                screen.displayMessage("Account Balance: $" + std::to_string(dataBase.getBalanceByIndex(index)));
                std::this_thread::sleep_for(std::chrono::seconds(5));

                break;

            case Choice::WithdrawCash:

                screen.displayWithdrawMenu();
                userWithdrawChoice = static_cast<WithdrawChoice>(stoi(keypad.getInput()));

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

                if (amount != 0)
                {
                    excuteTransaction();
                    screen.displayMessage("Pick your $" + std::to_string(amount));
                    std::this_thread::sleep_for(std::chrono::seconds(5));
                    cashDispenser.dispenseCash(amount);
                }
                
                
                
                break;

            case Choice::DepositFunds:
                screen.displayMessage("Please Enter the amount: ");
                userDepositChoice = keypad.getInput();

                userDepositAmount = stoul(userDepositChoice);

                if (
                    depositSlot.receiveEnvelops() &&
                    userDepositAmount > 0 && 
                    cashDispenser.getAvailBills() + userDepositAmount <= cashDispenser.MAX_CASH
                    )
                {
                    
                    dataBase.depositByIndex(index, userDepositAmount);
                    cashDispenser.addCash(userDepositAmount);
                    screen.displayMessage("You have deposited $" + std::to_string(userDepositAmount));
                    std::this_thread::sleep_for(std::chrono::seconds(5));


                }
                else if (
                    depositSlot.receiveEnvelops() && 
                    userDepositAmount > 0 && 
                    cashDispenser.getAvailBills() + userDepositAmount > cashDispenser.MAX_CASH
                    )

                {
                    amount = cashDispenser.MAX_CASH - cashDispenser.getAvailBills();
                    screen.displayMessage("ATM is full, you have deposited $" + std::to_string(amount));
                    dataBase.depositByIndex(index, amount);
                    screen.displayMessage("Please receive back your $" + std::to_string(userDepositAmount - amount));
                    std::this_thread::sleep_for(std::chrono::seconds(5));

                }
                
                excuteTransaction();
                
                break;

            case Choice::Exit:
                customer.~User();
                run();
            
            default:
                screen.displayMessage("Invalid Input");
                std::this_thread::sleep_for(std::chrono::seconds(1));
                
            }
            
        }
    }
    else
    {
        screen.displayMessage("Invalid User or PIN\n-----------------------");
        std::this_thread::sleep_for(std::chrono::seconds(3));
        run();
    } 
}
// this returns Account index if valid, if not returns -1
int Atm::authenticateUser(std::string& userId, std::string& PIN)
{
    int accountIndex = -1;
    if(dataBase.validateAccount(userId, PIN, accountIndex)) {
        customer.setStatus(true);
    }

    return accountIndex;

}

void Atm::excuteTransaction(/* args */)
{
    dataBase.saveData();
}