#include "CashDispenser.h"

// constructor
CashDispenser::CashDispenser()
{
    availCash = 500 * 20;
}

// give money to the user from the cash dispenser
void CashDispenser::dispenseCash(unsigned int amount) 
{
    availCash -= amount;
}

// refill the cash dispenser
void CashDispenser::resetDispenser()
{
    availCash = 10000;
}

// get cash amount from the cash dispenser
unsigned int CashDispenser::getAvailBills()
{
    return availCash;
}

// if user deposited amount it should be added into the case mashine
void CashDispenser::addCash(unsigned int amount)
{
    availCash += amount;
}