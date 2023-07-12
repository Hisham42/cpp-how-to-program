#include <iostream>
#include <array>
#include <iomanip>

using namespace std;


const int mazeRows = 12;
const int mazeColumns = 12;
char PREV{'h'};

int currentRow{2};
int currentColumn{0};

bool MOVE{true};



void moveRight();
void moveLeft();
void moveUp();
void moveDown();
void moveCheck();
void move();
void mazeTraversal();
void moveSwitch(char &move);

void continueMoving();

void displayMaze(char (*arr)[mazeRows]);



char maze [mazeRows][mazeColumns] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#'},
        {'.', '.', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#'},
        {'#', '#', '#', '.', '#', '.', '.', '.', '.', '#', '.', '#'},
        {'#', '.', '.', '.', '.', '#', '#', '#', '.', '#', '.', '.'},
        {'#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
        {'#', '.', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
        {'#', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#'},
        {'#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    };

int main() {

    maze[currentRow][currentColumn] = 'X';

    mazeTraversal();  
}

void displayMaze(char (*arr)[mazeRows]) {

    for (size_t i = 0; i < mazeRows; i++)
    {
        for (size_t j = 0; j < mazeColumns; j++)
        {
            cout << setw(3) << arr[i][j];
            cout << setw(2) << " ";
        }
        cout << endl;        
    }
    cout << endl;
}

void mazeTraversal() {

    move();

    if (MOVE) // boundry condition
    { 
        displayMaze(maze);

        mazeTraversal();
    }
    
}

void move() {

    char move{'h'};
    int x{0};

    //if only one . avail >> move to it
    {
        if (maze[currentRow][currentColumn + 1] == '.')
        {
            move = 'r';
            x += 1;
        }

        if (maze[currentRow][currentColumn - 1] == '.')
        {
            move = 'l';
            x += 1;
        }

        if (maze[currentRow + 1][currentColumn] == '.')
        {
            move = 'd';
            x += 1;
        }

        if (maze[currentRow - 1][currentColumn] == '.')
        {
            move = 'u';
            x += 1;
        }
    }
    //Uni Move
    if (x == 1)
    {
        moveSwitch(move);
        
    }
    // if you have more than one . avail
    else if (x > 1)
    {
        if (PREV == 'l' && maze[currentRow - 1][currentColumn] != '#')
            {
                moveUp();
                
            }
        else if (PREV == 'r' && maze[currentRow + 1][currentColumn] != '#')
            {
                moveDown();   
            }
        else if (PREV == 'u' && maze[currentRow][currentColumn + 1] != '#')
            {
                moveRight();
            }
        else if (PREV == 'd' &&maze[currentRow][currentColumn - 1] != '#')
            {
                
                moveLeft();
            
            }
        else 
            {
                continueMoving();
            }
        
    }
    
    //if you donot have . avail (Only X Avail)
    else if (x == 0)
    {
        //only one X avail
        int y{0};
        
        {
            if (maze[currentRow][currentColumn + 1] == 'X')
            {
                move = 'r';
                y += 1;
            }

            if (maze[currentRow][currentColumn - 1] == 'X')
            {
                move = 'l';
                y += 1;
            }

            if (maze[currentRow + 1][currentColumn] == 'X')
            {
                move = 'd';
                y += 1;
            }

            if (maze[currentRow - 1][currentColumn] == 'X')
            {
                move = 'u';
                y += 1;
            }
        }
        if (y == 1)
        {
            moveSwitch(move); 
        }
    
        //more than X avail
        else if (y > 1)
        {   
            y = 0;
            // depend on prev move plus avail Xs
            if (maze[currentRow][currentColumn + 1] == 'X' && PREV != 'l')
            {
                move = 'r';
                y += 1;
            }

            if (maze[currentRow][currentColumn - 1] == 'X' && PREV != 'r')
            {
                move = 'l';
                y += 1;
                
            }

            if (maze[currentRow + 1][currentColumn] == 'X' && PREV != 'u')
            {
                move = 'd';
                y += 1;
                
            }

            if (maze[currentRow - 1][currentColumn] == 'X' && PREV != 'd')
            {
                move = 'u';
                y += 1 ;
                
            }

            if (y == 1)
            {
                moveSwitch(move);
            }

            if (y > 1) // cant take dicision
            {
                /* continue moving*/

                switch (PREV)
                {
                    case 'l':
                        moveLeft();
                        break;

                    case 'r':
                        moveRight();
                        break;

                    case 'u':
                        moveUp();
                        break;

                    case 'd':
                        moveDown();
                        break;
                    
                    default:
                        break;
                }

            }
            
            
            
            
    
        }
        
    }
    
    else
    {
        MOVE = false;
    }

}

void moveRight() {

    currentColumn += 1;
    moveCheck();
    PREV = 'r';

}

void moveLeft() {
    
    currentColumn += -1;
    moveCheck();
    PREV = 'l';

}

void moveUp() {

    currentRow += -1;
    moveCheck();
    PREV = 'u';

}

void moveDown() {

    currentRow += 1;
    moveCheck();
    PREV = 'd';

}

void moveCheck() {

    if (maze[currentRow][currentColumn] != '#')
    {
        maze[currentRow][currentColumn] = 'X';
    }
    else
    {
        cout << "Maze Solved or Cannot move!" << endl;
        MOVE = false;
    }
    
}

void moveSwitch(char &move) {
    
    switch (move)
        {
            case 'u':
                moveUp();
                break;
            case 'd':
                moveDown();
                break;
            case 'l':
                moveLeft();
                break;

            case 'r':
                moveRight();
                break;
            
            default:
                cout << "Maze Solved or Cannot move!"  << endl;
                break;
        }
}

void continueMoving() {

    switch (PREV)
        {
            case 'u':
                moveUp();
                break;
            case 'd':
                moveDown();
                break;
            case 'l':
                moveLeft();
                break;

            case 'r':
                moveRight();
                break;
            
            default:
                cout << "Maze Solved or Cannot move!" << endl;
                break;
        }
}