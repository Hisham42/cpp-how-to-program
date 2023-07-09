#include <iostream>
#include <array>
#include <iomanip>

using namespace std;

//GLOBAL variables


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

int QUEENS = 8;
int START = 0;

//print chessboard
void displayChessboard();
void displayImaginaryArray();
bool placeQueen(int queenNumber, int row);
void unblock(int queenNumber);
void recursiveQueen(int queenNumber = 1, int row= 0);

//update imaginary array
void updateImaginaryArray(int x, int y,int queenNumber);

int main() {


    START = 7;
    recursiveQueen();
    displayChessboard();
 

}


void updateImaginaryArray(int x, int y, int queenNumber) {

    for (size_t i = 0; i < ROWS; i++)
    {   
        //update vertical
        if (imaginaryArray[x][i] == 0)
        {
            imaginaryArray[x][i] = queenNumber;
        }
        
        

        //update horizontal
        if (imaginaryArray[i][y] == 0)
        {
            imaginaryArray[i][y] = queenNumber;
        }

        //update diagonal first
        if (x + i <= 7 && x + i >= 0 && y + i <= 7 && y + i >= 0 && imaginaryArray[x + i][y + i] == 0)
        {
            imaginaryArray[x + i][y + i] = queenNumber;
        }
        
        if (x - i <= 7 && x - i >= 0 && y - i <= 7 && y - i >= 0 && imaginaryArray[x - i][y - i] == 0)
        {
            imaginaryArray[x - i][y - i] = queenNumber;
        }

        //update diagonal second
        if (x + i <= 7 && x + i >= 0 && y - i <= 7 && y - i >= 0 && imaginaryArray[x + i][y - i] == 0)
        {
            imaginaryArray[x + i][y - i] = queenNumber;
        }
        
        if (x - i <= 7 && x - i >= 0 && y + i <= 7 && y - i >= 0 && imaginaryArray[x - i][y + i] ==0)
        {
            imaginaryArray[x - i][y + i] = queenNumber;
        }

    }
    
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

bool placeQueen(int queenNumber, int row){
    
    if (queenNumber == 1)
    {
        chessBoard[row][START] = queenNumber;
        updateImaginaryArray(row, START, queenNumber);
        return true;
    }
    
    for (size_t i = 0; i < COLUMNS; i++)
    {
        if (imaginaryArray[row][i] == 0)
        {
            chessBoard[row][i] = queenNumber;
            updateImaginaryArray(row, i, queenNumber);
            return true;
        }
    }
    return false;
}


void recursiveQueen(int queenNumber, int row) {

    if (queenNumber <= QUEENS)
    {
        if (placeQueen(queenNumber, row))
        {

            recursiveQueen(queenNumber + 1, row + 1);
        }
        else
        {
            unblock(queenNumber - 1);
            
            
            recursiveQueen(queenNumber - 1, row - 1);
        }
    }
     
}

void unblock(int queenNumber) {

    //remove 99 for queenNumber + 1
    int m = queenNumber;

    for (size_t n = 0; n < COLUMNS; n++)
    {
        //reset chessboard
        if (imaginaryArray[m][n] == 99)
        {
            imaginaryArray[m][n] = 0;
        }
    } 
    



    for (size_t i = 0; i < ROWS; i++)
    {
        for (size_t j = 0; j < COLUMNS; j++)
        {   
            //update imaginary
            
            if (imaginaryArray[i][j] == queenNumber)
            {
                if (chessBoard[i][j] != queenNumber)
                {
                    imaginaryArray[i][j] = 0;
                }
                if (chessBoard[i][j] == queenNumber)
                {
                    imaginaryArray[i][j] = 99;
                }
                
            }
        }
    }

    int k = queenNumber - 1;

    for (size_t l = 0; l < COLUMNS; l++)
    {
        //reset chessboard
        if (chessBoard[k][l] == queenNumber)
        {
            chessBoard[k][l] = 0;
        }
    } 
    

    

}
