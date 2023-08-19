#include "vicoba.h"

int main()
{
    Vicoba Ahmed(200000, 5);
    Vicoba::setAnnualInterestRate(13);
    Ahmed.getToBePaid();
    Ahmed.getToBePaidMonthly();
}