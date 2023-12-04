#ifndef CashDispenser_H
#define CashDispenser_H

class CashDispenser
{
private:
    

    unsigned int availCash;
public:

    const unsigned int MAX_CASH = 10000;
    
    CashDispenser();

    void dispenseCash(unsigned int amount);
    
    void resetDispenser();

    void addCash(unsigned int amount);


    unsigned int getAvailBills();

};



#endif