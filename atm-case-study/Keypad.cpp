#include <iostream>
#include "Keypad.h"

// get input from user
std::string Keypad::getInput()
{
    std::cin.clear();
    std::string userInput;
    std::cin >> userInput;

    return userInput;
}

