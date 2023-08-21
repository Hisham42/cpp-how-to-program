#include "deck.h"

#ifndef HAND_H
#define HAND_H

class Hand
{
private:
    Card hand[5];
    bool pair;
    bool twoPairs;
    bool threeOfKind;
    bool fourOfKind;
    bool flush;
    bool straight;
    int highCard;
    int rank;
    static int handNumber;

    void evaluate();
    void initilizeAttributes();

public:
    Hand(Deck&);
    Hand(Card&, Card&, Card&, Card&, Card&);
    ~Hand();
    void print();
    
    void compare(Hand&);

    void replace(Deck&);
    void replace(Hand&);
    
    
  
};

    
#endif
