#include "deck.h"
#include "hand.h"
#include <iostream>

int main()
{

    cout << "======HAND 1=======" << endl;
    Deck H;
    H.shuffle();
    Hand h1(H);
    h1.print();
    

    cout << "======HAND 2=======" << endl;

    H.dealCard();
    Hand h2(H);
    h2.print();
   

    cout << "======+++++++++++++======" << endl;


  

    h1.replace(H);

    h1.compare(h2);

    
    
   
    
}