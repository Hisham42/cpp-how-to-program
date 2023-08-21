#include "hand.h"
#include <iostream>

Hand::Hand(Deck& a)
{
    initilizeAttributes();
    for (size_t i = 0; i < 5; i++)
    {
        if (a.moreCards())
        {
            hand[i] = a.dealCard();
        }
    }
}

Hand::Hand(Card& a, Card& b, Card& c, Card& d, Card& e)
{
    initilizeAttributes();
    hand[0] = a;
    hand[1] = b;
    hand[2] = c;
    hand[3] = d;
    hand[4] = e;

}

Hand::~Hand()
{
}

void Hand::print()
{
    evaluate();

    for (int i = 0; i < 5; i++)
    {
        cout << hand[i].toString() << endl;
    }

    

    
    cout << "============" << endl;
    

    switch (rank)
    {
    case 1:
        cout << "Royal Flush" << endl;
        break;
    case 2:
        cout << "Straight Flush" << endl;
        break;
    case 3:
        cout << "Four Of A Kind" << endl;
        break;
    case 4:
        cout << "Full House" << endl;
        break;
    case 5:
        cout << "Flush" << endl;
        break;
    case 6:
        cout << "Straight" << endl;
        break;
    case 7:
        cout << "Three Of A Kind" << endl;
        break;
    case 8:
        cout << "Two Pair" << endl;
        break;
    case 9:
        cout << "One Pair" << endl;
        break;
    
    default:
        cout << "High Card is: " << hand->strFace(highCard) << endl;
        break;
    }

    
    cout << endl;
        
    
}

void Hand::evaluate()
{   
    initilizeAttributes();
    //contains a pair
    int count{0};
    int flushCount{0};
    int minValue{12};


    for (int i = 0; i < 5; i++)
    {
        if (minValue > hand[i].getFace())
        {
            minValue = hand[i].getFace();
        }
        
        for (int j = i + 1; j < 5; j++)
        {   
            if (i != j)
            {
                if (hand[i].getFace() == hand[j].getFace())
                {
                    count++;         
                }
                if (i == 0 && hand[i].getSuit() == hand[j].getSuit())
                {
                    flushCount++;
                }    
            }
        }
    }

    highCard = minValue;

    int maxValue{minValue + 4};
    int controller{99};
    int straightInt{0};
    
    while (maxValue > minValue)
    {
        controller = 0;

        for (int i = 0; i < 5; i++)
        {
            if (hand[i].getFace() == maxValue)
            {
                straightInt++;
                controller++;
                maxValue--;
                break;
            }
        }
        if (controller == 0)
        {
            break;
        }
    }


    if (straightInt == 4)
    {
        straight = true;
    }
    else if (flushCount == 4)
    {
        flush = true;
    }
    else if (count == 6)
    {
        fourOfKind = true;
    }
    else if (count == 4)
    {
        threeOfKind = true;
        pair = true;
    }
    else if (count == 3)
    {
        threeOfKind = true;
    }
    else if (count == 2)
    {
        twoPairs = true;
    }
    else if (count == 1)
    {
        pair = true;
    }


    if (highCard == 0 && flush == true)
    {
        rank = 1;
    }
    else if (straight == true && flush == true)
    {
        rank = 2;
    }
    
    else if (fourOfKind == true)
    {
        rank = 3;
    }

    else if (threeOfKind == true && pair == true)
    {
        rank = 4;
    }
    else if (flush == true)
    {
        rank = 5;
    }
    else if (straight == true)
    {
        rank = 6;
    }
    else if (threeOfKind == true)
    {
        rank = 7;
    }
    else if (twoPairs == true)
    {
        rank = 8;
    }
    else if (pair == true)
    {
        rank = 9;
    }
    
    

}

void Hand::compare(Hand& a)
{
    evaluate();
    a.evaluate();
    if (rank != 0 && a.rank != 0)
    {
        if (rank > a.rank)
        {
            cout << "Hand 2 Wins!" << endl;
        }
        else if (rank < a.rank)
        {
            cout << "Hand 1 Wins!" << endl;
        }
        else
        {
            if (highCard < a.highCard)
            {
                cout << "Hand 1 Wins!" << endl;
            }
            else if (highCard > a.highCard)
            {
                cout << "Hand 2 Wins!" << endl;
            }
            else
            {
                cout << "Draw!" << endl;
            } 
        }
    }
    else
        {
            if (highCard < a.highCard)
            {
                cout << "Hand 1 Wins!" << endl;
            }
            else if (highCard > a.highCard)
            {
                cout << "Hand 2 Wins!" << endl;
            }
            else
            {
                cout << "Draw!" << endl;
            } 
        }

}


void Hand::replace(Deck& D)
{
    int choiceCount{0};
    string input;
    while(choiceCount < 3)
    {

    
        int choice{0};
        

        while ((choice < 1 || choice > 5) && choice != 99)
        {
            
            cout << "Please enter card number from 1 to 5 to replace, or 99 to quit" << endl;
            cin >> input;

            choice = stoi(input);
            
        }
    
        if (choice == 99)
            {
                break;
            }
        else
        {
            hand[choice - 1] = D.dealCard();
            
            print();
        }

        choiceCount++;
    }
}

void Hand::replace(Hand& H)
{
    int choiceCount{0};
    string input;
    string inpoppo;
    int choice{0};
    int opp{0};

    while(choiceCount < 3)
    {
        while ((choice < 1 || choice > 5) && choice != 99)
        {  
            cout << "Please enter card number from 1 to 5 to replace, or 99 to quit" << endl;
            cin >> input;
            choice = stoi(input);

        }

        if (choice == 99)
            {
                break;
            }
        else
        {
            while ((opp < 1 || opp > 5))
            {
                cout << "Please enter card number have from your opponenet" << endl;
                cin >> inpoppo;
                opp = stoi(inpoppo);
                
            }
        }

        Card temp = H.hand[opp - 1];
        H.hand[opp - 1] = hand[choice - 1];
        hand[choice - 1] = temp;

        print();
        H.print();
       

        choiceCount++;
    }
}

void Hand::initilizeAttributes()
{
    pair = false;
    twoPairs = false;
    threeOfKind = false;
    fourOfKind = false;
    flush = false;
    straight = false;
    highCard = 12;
    rank = 0;
    
}