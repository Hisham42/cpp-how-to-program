#include "Screen.h"
#include <iomanip>

void Screen::displayMessage(const std::string& message)
{
    std::cout << std::setprecision(2) << message << std::endl;
}

void Screen::displayMainMenu()
{
    std::cout << "Main menu:\n"
    << std::setw(5) << " " << "1 - View my balance\n"
    << std::setw(5) << " " << "2 - Withdraw cash\n"
    << std::setw(5) << " " << "3 - Deposit funds\n"
    << std::setw(5) << " " << "4 - Exit\n"
    << "Enter a choice" << std::endl;
}

void Screen::displayWithdrawMenu()
{
    std::cout << "Withdraw options:\n"
    << std::setw(5) << " " << "1 - $20"
    << std::setw(5) << " " << "4 - $100\n"
    << std::setw(5) << " " << "2 - $40"
    << std::setw(5) << " " << "5 - $200\n"
    << std::setw(5) << " " << "3 - $60"
    << std::setw(5) << " " << "6 - Cancel transaction\n"
    << "Choose a withdrawal option (1-6):" << std::endl;
}

