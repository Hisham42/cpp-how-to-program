#include <iostream>
#include <array>
#include <iomanip>
#include <random>

using namespace std;

//global variables
int heuristic [8][8];


//global rows and columns
const int ROWS = 8;
const int COLUMNS = 8;

//imaginary array
int imaginaryArray[ROWS][COLUMNS];

//chess board
int chessBoard[ROWS][COLUMNS];

int currentRow{0};
int currentColumn{0};
int counter{1};

int MOVES = 8;


//functions prototypes

//initiate first queen's place
void initiateQueen(int row, int column);

//print chessboard
void displayChessboard();
void displayImaginaryArray();
void displayHeuristicArray();

//set the next queen position
void setAnotherQueen();

//update imaginary array
void updateImaginaryArray(int x, int y);
void clearArrays();



default_random_engine engine(static_cast<unsigned int>(time(0)));

uniform_int_distribution <unsigned int> randomInt(0, 7);

int main() {

    while (true)
    {
        clearArrays();

        initiateQueen(randomInt(engine), randomInt(engine));

        for (size_t i = 0; i < MOVES; i++)
        {
            setAnotherQueen();
        }

        displayChessboard();

        cout << endl;

        displayImaginaryArray();
            
            
        cout << "\n" << counter << endl;  

        if (counter == 8)
        {
            break;
        }
    }
    
}

void initiateQueen(int row, int column){
    currentRow = row;
    currentColumn = column;
    chessBoard[currentRow][currentColumn] = 1;
    updateImaginaryArray(row, column);
}



void displayChessboard() {


    cout << setw(3) << " ";

    for (size_t i = 0; i < COLUMNS; i++)
    {
        cout << setw(3) << i;
        cout << setw(2) << " ";
    }

    cout << endl;
    
    for (size_t i = 0; i < ROWS; i++)
    {
        cout << i;
        cout << setw(2) << " ";
        
        for (size_t j = 0; j < COLUMNS; j++)
        {
            cout << setw(3) << chessBoard[i][j];
            cout << setw(2) << " ";
        }
        cout << endl;
        
    }
    
    
}

void updateImaginaryArray(int x, int y) {

    for (size_t i = 0; i < ROWS; i++)
    {
        //update vertical
        imaginaryArray[x][i] = 99;

        //update horizontal
        imaginaryArray[i][y] = 99;

        //update diagonal first
        if (x + i <= 7 && x + i >= 0 && y + i <= 7 && y + i >= 0)
        {
            imaginaryArray[x + i][y + i] = 99;
        }
        
        if (x - i <= 7 && x - i >= 0 && y - i <= 7 && y - i >= 0)
        {
            imaginaryArray[x - i][y - i] = 99;
        }

        //update diagonal second
        if (x + i <= 7 && x + i >= 0 && y - i <= 7 && y - i >= 0)
        {
            imaginaryArray[x + i][y - i] = 99;
        }
        
        if (x - i <= 7 && x - i >= 0 && y + i <= 7 && y - i >= 0)
        {
            imaginaryArray[x - i][y + i] = 99;
        }

    }
    
}

void displayImaginaryArray() {


    cout << setw(3) << " ";

    for (size_t i = 0; i < COLUMNS; i++)
    {
        cout << setw(3) << i;
        cout << setw(2) << " ";
    }

    cout << endl;
    
    for (size_t i = 0; i < ROWS; i++)
    {
        cout << i;
        cout << setw(2) << " ";
        
        for (size_t j = 0; j < COLUMNS; j++)
        {
            cout << setw(3) << imaginaryArray[i][j];
            cout << setw(2) << " ";
        }
        cout << endl;
        
    }
    
    
}


void setAnotherQueen() {

    int i = counter;

    while (counter == i)
    {
        int x = randomInt(engine);
        int y = randomInt(engine);
        
        if (imaginaryArray[x][y] == 0)
        {
            initiateQueen(x, y);
            counter++;
        }
        else
        {
            break;
        }
    }
    
}

void clearArrays() {

    for (size_t i = 0; i < ROWS; i++)
    {
        for (size_t j = 0; j < COLUMNS; j++)
        {
            chessBoard[i][j] = 0;
            imaginaryArray[i][j] = 0;
        }
    }
    counter = 1;
    
}