#include "tictactoe.h"

Tictactoe2::Tictactoe2()
{
    initializeArray();

    
}

Tictactoe2::~Tictactoe2()
{
}

void Tictactoe2::player1(int r, int c)
{
    if (r >= 0 && r <= 2 && c >= 0 && c <= 2)
    {
        if (changeTurnPlayer1)
        {
            if (isEmpty(r, c))
            {
                playGround[r][c] = 1;
                changeTurnPlayer1 = false;
                changeTurnPlayer2 = true;
                displayGame();
                checkStatus();
                if (checkDraw())
                {
                    std::cout << "Game is DRAW!" << std::endl;
                }
                
            }
            else
            {
                std::cout << "Player 1: Position is not empty" << std::endl;
            }
        }
        else
        {
            std::cout << "Player 2: Not his turn" << std::endl;
        }
    }
    else
    {
        std::cout << "Player 2: Invalid Row or Column" << std::endl;
    }
    

}

void Tictactoe2::player2(int r2, int c2)
{
    if (r2 >= 0 && r2 <= 2 && c2 >= 0 && c2 <= 2)
    {
        if (changeTurnPlayer2)
        {
            if (isEmpty(r2, c2))
            {
                playGround[r2][c2] = 2;
                changeTurnPlayer1 = true;
                changeTurnPlayer2 = false;
                displayGame();
                checkStatus();
                if (checkDraw())
                {
                    std::cout << "Game is DRAW!" << std::endl;
                }
            }
            else
            {
                std::cout << "Player 2: Position is not empty" << std::endl;
            }
        }
        else
        {
            std::cout << "Player 2: Not his turn" << std::endl;
        }
    }
    else
    {
        std::cout << "Player 2: Invalid Row or Column" << std::endl;
    }
    
}


void Tictactoe2::initializeArray()
{
    
    

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            playGround[i][j] = 0;
        }
        
    }

    changeTurnPlayer1 = true;

    
    
    
}

bool Tictactoe2::isEmpty(int r, int c)
{
    if (playGround[r][c] == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

void Tictactoe2::displayGame()
{
    std::cout << " -----------------" << std::endl;


    for (size_t i = 0; i < ROWS; i++)
    {
        std::cout << "|";
        for (size_t j = 0; j < COLUMNS; j++)
        {
            std::cout << std::setw(3) << playGround[i][j] << "  |";
        }

        std::cout <<std::endl;
        
    }


    std::cout << " -----------------" << std::endl;
}

void Tictactoe2::checkStatus()
{
    for (size_t i = 0; i < ROWS; i++)
    {
        for (size_t j = 0; j < COLUMNS; j++)
        {
            checkCell_LRUPD(i, j);
        }
        
    }
    
}

void Tictactoe2::checkCell_LRUPD(int r, int c)
{
    //corner case > Corner_Right_Down_Diagonal
   
    checkLeft(r, c);
    checkRight(r, c);
    checkUp(r, c);
    checkDown(r, c);
    checkDiagonal(r, c);

}

void Tictactoe2::checkRight(int r, int c)
{
    if (c == 0)
    {
        if (playGround[r][c] == playGround[r][c + 1] && playGround[r][c] ==  playGround[r][c + 2])
        {
            if (playGround[r][c] == 1)
            {
                std::cout << "Player 1: Wins!" << std::endl;
                exit(0);
            }
            else if (playGround[r][c] == 2)
            {
                std::cout << "Player 2: Wins!" << std::endl;
                exit(0);
            }
            
        }
    }
    
}

void Tictactoe2::checkLeft(int r, int c)
{
    if (c == 2)
    {
        if (playGround[r][c] == playGround[r][c - 1] && playGround[r][c] ==  playGround[r][c - 2])
        {
            if (playGround[r][c] == 1)
            {
                std::cout << "Player 1: Wins!" << std::endl;
                exit(0);
            }
            else if (playGround[r][c] == 2)
            {
                std::cout << "Player 2: Wins!" << std::endl;
                exit(0);
            }
            
        }
    }
    
}

void Tictactoe2::checkUp(int r, int c)
{
    if (r == 2)
    {
        if (playGround[r][c] == playGround[r - 1][c] && playGround[r][c] ==  playGround[r - 2][c])
        {
            if (playGround[r][c] == 1)
            {
                std::cout << "Player 1: Wins!" << std::endl;
                exit(0);
            }
            else if (playGround[r][c] == 2)
            {
                std::cout << "Player 2: Wins!" << std::endl;
                exit(0);
            }
            
        }
    }
    
}

void Tictactoe2::checkDown(int r, int c)
{
    if (r == 0)
    {
        if (playGround[r][c] == playGround[r + 1][c] && playGround[r][c] ==  playGround[r + 2][c])
        {
            if (playGround[r][c] == 1)
            {
                std::cout << "Player 1: Wins!" << std::endl;
                exit(0);
            }
            else if (playGround[r][c] == 2)
            {
                std::cout << "Player 2: Wins!" << std::endl;
                exit(0);
            }
            
        }
    }
    
}

void Tictactoe2::checkDiagonal(int r, int c)
{
    if (r == 0 && c == 0)
    {
        if (playGround[r][c] == playGround[r + 1][c + 1] && playGround[r][c] ==  playGround[r + 2][c + 2])
        {
            if (playGround[r][c] == 1)
            {
                std::cout << "Player 1: Wins!" << std::endl;
                exit(0);
            }
            else if (playGround[r][c] == 2)
            {
                std::cout << "Player 2: Wins!" << std::endl;
                exit(0);
            }
            
        }
    }

    else if (r == 0 && c == 2)
    {
        if (playGround[r][c] == playGround[r + 1][c - 1] && playGround[r][c] ==  playGround[r + 2][c - 2])
        {
            if (playGround[r][c] == 1)
            {
                std::cout << "Player 1: Wins!" << std::endl;
                exit(0);
            }
            else if (playGround[r][c] == 2)
            {
                std::cout << "Player 2: Wins!" << std::endl;
                exit(0);
            }
            
        }
    }
    
}

bool Tictactoe2::checkDraw()
{
    for (size_t i = 0; i < ROWS; i++)
    {
        for (size_t j = 0; j < COLUMNS; j++)
        {
            if (playGround[i][j] == 0)
            {
                return false;
            }
             
        }
        
    }

    return true;
    
}
