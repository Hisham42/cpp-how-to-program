#include "card.h"
#include <vector>

#ifndef DECK_H
#define DECK_H


const int NUMBEROFCARDS = 52;


class Deck
{
private:
    Card deck[NUMBEROFCARDS];
    int currentCard;

    void deckInitializer();

public:

    Deck();
    ~Deck();

    void shuffle();
    void dealDeck();
    Card dealCard();
    bool moreCards();

};


#endif

int generateRandom();
bool inVector(int a, vector<int>&);