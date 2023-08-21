#include "card.h"
#include <sstream>

enum Faces{
    Ace, King, Queen, Jack,
    Ten, Nine, Eight,Seven,
    Six, Five, Four, Three, Two
};

enum Suits{Spades, Diamonds, Clubs, Hearts};

static int arrayOfFaces[13] = {
    Ace, King, Queen, Jack,
    Ten, Nine, Eight,Seven,
    Six, Five, Four, Three, Two   
};

static int arrayOfSuits[4] = {Clubs, Diamonds, Hearts, Spades};

Card::Card(int f, int s)
{
    Card::setFace(f);
    Card::setSuit(s);
    
}
Card::Card()
{
    face = 99;
    suit = 99;
}

Card::~Card()
{
}

int Card::getFace() const
{
    return face;
}

int Card::getSuit() const
{
    return suit;
}

void Card::setFace(int a)
{
    switch (a)
    {
        case Jack:
            face = Faces::Jack;
            break;

        case Ace:
            face = Faces::Ace;;
            break;

        case Two:
            face = Faces::Two;
            break;

        case Three:
            face = Faces::Three;;
            break;

        case Four:
            face = Faces::Four;
            break;

        case Five:
            face = Faces::Five;
            break;

        case Six:
            face = Faces::Six;
            break;

        case Seven:
            face = Faces::Seven;
            break;

        case Eight:
            face = Faces::Eight;
            break;

        case Nine:
            face = Faces::Nine;
            break;

        case Ten:
            face = Faces::Ten;
            break;

        case Queen:
            face = Faces::Queen;
            break;

        case King:
            face = Faces::King;
            break;
        
        default:
            throw invalid_argument("Invalid face.");
            break;
    }  
}

void Card::setSuit(int b)
{
    switch (b)
    {
    case Suits::Clubs:
        suit = Suits::Clubs;
        break;
    case Suits::Diamonds:
        suit = Suits::Diamonds;
        break;
    case Suits::Hearts:
        suit = Suits::Hearts;
        break;
    case Suits::Spades:
        suit = Suits::Spades;
        break;
    
    default:
        throw invalid_argument("Invalid face.");
        break;
    }
    
}

string Card::toString()
{
    ostringstream output;
    output << strFace(getFace()) + " of " + strSuit(getSuit());
    return output.str();
}

string Card::strFace(int a)
{
    switch (a)
    {
    case Faces::Ace :
        return "Ace";
        break;
    case Faces::King :
        return "King";
        break;
    case Faces::Queen :
        return "Queen";
        break;
    case Faces::Jack :
        return "Jack";
        break;
    case Faces::Ten :
        return "Ten";
        break;
    case Faces::Nine :
        return "Nine";
        break;
    case Faces::Eight :
        return "Eight";
        break;
    case Faces::Seven :
        return "Seven";
        break;
    case Faces::Six :
        return "Six";
        break;
    case Faces::Five :
        return "Five";
        break;
    case Faces::Four :
        return "Four";
        break;
    case Faces::Three :
        return "Three";
        break;
    case Faces::Two :
        return "Two";
        break;
    
    default:
        throw invalid_argument("Invalid face.");
        break;
    }
}

string Card::strSuit(int b)
{
    switch (b)
    {
    case Suits::Clubs :
        return "Clubs";
        break;

    case Suits::Spades :
        return "Spades";
        break;

    case Suits::Hearts :
        return "Hearts";
        break;

    case Suits::Diamonds :
        return "Diamonds";
        break;
    
    default:
        throw invalid_argument("Invalid Suit.");
        break;
    }
}