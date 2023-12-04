#include "CashDispenser.h"

CashDispenser::CashDispenser()
{
    availCash = 500 * 20;
}

void CashDispenser::dispenseCash(unsigned int amount) 
{
    availCash -= amount;
}

void CashDispenser::resetDispenser()
{
    availCash = 500;
}

unsigned int CashDispenser::getAvailBills()
{
    return availCash;
}

void CashDispenser::addCash(unsigned int amount)
{
    availCash += amount;
}