#include <iostream>
#include "Keypad.h"

std::string Keypad::getInput()
{
    std::cin.clear();
    std::string userInput;
    std::cin >> userInput;

    return userInput;
}

