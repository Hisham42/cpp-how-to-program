#ifndef Atm_H
#define Atm_H

#include "Screen.h"
#include "Keypad.h"
#include "CashDispenser.h"
#include "DepositSlot.h"
#include "User.h"
#include "DataBase.h"


class Atm
{
private:

    std::string BankName;
    int authenticateUser(std::string& userId, std::string& PIN);

    void excuteTransaction();

    Screen screen;
    Keypad keypad;
    CashDispenser cashDispenser;
    DepositSlot depositSlot;
    User customer;
    DataBase dataBase;

public:
    Atm(const std::string& bankName);
    void run();

};



#endif