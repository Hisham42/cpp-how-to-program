#ifndef CashDispenser_H
#define CashDispenser_H

class CashDispenser
{
private:
    unsigned int availCash; // avail cash in the dispenser
public:

    const unsigned int MAX_CASH = 10000; // max cash that the machine can have
    
    CashDispenser();

    void dispenseCash(unsigned int amount); // withdraw cash
    
    void resetDispenser(); // refill machine

    void addCash(unsigned int amount); // in case of deposit cash


    unsigned int getAvailBills(); // get avail cash in the machine

};



#endif