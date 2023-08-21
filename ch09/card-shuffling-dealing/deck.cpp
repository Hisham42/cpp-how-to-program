#include "deck.h"
#include <iostream>
#include <random>
#include <iomanip>


/* Deck Constructor */
Deck::Deck()
{
    deckInitializer(); 
    currentCard = 0;
}

/* Destructor */
Deck::~Deck()
{
    cout << "=========Program exit succesfully=========" << endl;
}

/* Shuffle Cards */
void Deck::shuffle()
{
    //pick a card based on i
    //pick another card based on random number

    //track i and random number in a vector

    Card tempCard;
    int i{0};
    int j{0};

    vector<int> numbersTrack;

    while(numbersTrack.size() < 52)
    {
        j = generateRandom();

        while (inVector(j, numbersTrack) || j == i)
        {
            j = generateRandom();
        }
        
        if (!inVector(i, numbersTrack))
        {
            tempCard = deck[i];
            deck[i] = deck[j];
            deck[j] = tempCard;
            numbersTrack.push_back(i);
            numbersTrack.push_back(j);
        }
        i++;
    }
          
}

/* Initilize array of cards */
void Deck::deckInitializer()
{
    int i{0};
    int j{0};
    int k{0};

    while(k < 52)
    {
        
        deck[k].setFace(i);

        deck[k].setSuit(j);
        
        
        j++;
        k++;
        if (j == 4)
        {
            i++;
            j = 0;
        }
    }
}

int generateRandom()
{
    random_device rd;

    mt19937 engine(rd());

    uniform_int_distribution <unsigned int> randomInt(0,51);

    return randomInt(engine);

}

bool inVector(int a, vector<int>& b)
{
    for (int i = 0; i < b.size(); i++)
    {
        if (a == b[i])
        {
            return true;
        }
    }
    return false;
}

void Deck::dealDeck()
{
    int count = 1;
    while (moreCards())
    {
        cout << setw(20) << dealCard().toString();
        

        if (count % 4 == 0)
        {
            cout << endl;
        }

        count++;
    }

    cout << endl;
    
}

Card Deck::dealCard()
{
    currentCard++;

    return deck[currentCard - 1];   
}

bool Deck::moreCards()
{
    if (currentCard == 52)
    {
        return false;
    }
    else
    {
        return true;
    }
    
}
