#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
#include <iomanip>

const int ROWS = 3;
const int COLUMNS = 3;



class Tictactoe2
{
private:
    /* 3-by-3 two-dimensional array of integers. */

    int playGround[ROWS][COLUMNS];
    bool changeTurnPlayer1{true};
    bool changeTurnPlayer2{false};
    void checkStatus();
    void initializeArray();
    bool isEmpty(int x, int y);
    void checkCell_LRUPD(int x1, int x2);
    void checkLeft(int r, int c);
    void checkRight(int r, int c);
    void checkUp(int r, int c);
    void checkDown(int r, int c);
    void checkDiagonal(int r, int c);
    bool checkDraw();

    
    

public:
    Tictactoe2();
    ~Tictactoe2();

    //player 1
    void player1(int row, int column);
    void player2(int row2, int column2);

    
    void displayGame();

};

#endif