#include <iostream>
#ifndef Screen_H
#define Screen_H

class Screen
{
private:

    std::string bankName;

public:

    void displayMessage(const std::string& message);
    void displayMainMenu();
    void displayWithdrawMenu();



};



#endif