#include "tictactoe.h"

using namespace std;

int main()
{
    Tictactoe2 game;

    game.player1(0, 0);
    game.player2(0, 1);

    game.player1(1, 1);
    game.player2(1, 0);
    
    game.player1(2, 1);
    game.player2(2, 2);

    game.player1(2, 0);
    game.player2(0, 2);

    game.player1(1, 2);

}