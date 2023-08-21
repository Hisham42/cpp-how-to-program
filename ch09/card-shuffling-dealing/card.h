#include <string>
using namespace std;



#ifndef CARD_H
#define CARD_H

class Card
{
private:
    int face;
    int suit;
    static int arrayOfFaces[13];
    static int arrayOfSuits[4];

public:
    Card(int, int);
    Card();
    ~Card();

    string toString();
    void setFace(int);
    void setSuit(int);

    int getFace() const;
    int getSuit() const;

    string strFace(int);
    string strSuit(int);

};





#endif