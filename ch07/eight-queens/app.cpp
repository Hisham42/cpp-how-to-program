#include <iostream>
#include <array>
#include <iomanip>

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

void calculateCurrentHeuristic();
void updateZeroHeuristic(int k, int l);

int main() {

    initiateQueen(4, 0);
    updateImaginaryArray(currentRow, currentColumn);
    calculateCurrentHeuristic();


    for (size_t i = 1; i < MOVES; i++)
    {
        if (counter == i)
        {
            setAnotherQueen();
        }         
    }
    
    displayChessboard();
            
            
    cout << "\n" << counter << endl;   
    
               

}

void initiateQueen(int row, int column){
    currentRow = row;
    currentColumn = column;
    chessBoard[currentRow][currentColumn] = 1;
}

void calculateCurrentHeuristic() {

    //copy blocked values to heuristic
    for (size_t i = 0; i < ROWS; i++)
    {
        for (size_t j = 0; j < COLUMNS; j++)
        {
            if (imaginaryArray[i][j] == 99)
            {
                heuristic[i][j] = 99;
            }
        }
    }

    //reset heuristic array
    for (size_t i = 0; i < ROWS; i++)
    {
        for (size_t j = 0; j < COLUMNS; j++)
        {
            if (heuristic[i][j] != 99)
            {
                heuristic[i][j] = 0;
            }
        }
    }

    for (size_t k = 0; k < ROWS; k++)
    {
        for (size_t l = 0; l < COLUMNS; l++)
        {
            if (heuristic[k][l] == 0)
            {               
                updateZeroHeuristic(k, l);                              
            }         
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

void displayHeuristicArray() {


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
            cout << setw(3) << heuristic[i][j];
            cout << setw(2) << " ";
        }
        cout << endl;
        
    }
    
    
}

void updateZeroHeuristic(int x, int y) {

    for (size_t i = 0; i < ROWS; i++)
    {
        //update vertical
        if (imaginaryArray[x][i] == 0)
        {
            heuristic[x][y] += 1;
            imaginaryArray[x][i] = 1;
        }

        //update horizontal
        if (imaginaryArray[i][y] == 0)
        {
            heuristic[x][y] += 1;
            imaginaryArray[i][y] = 1;
        }

        //update diagonal first
        if ((x + i <= 7 && x + i >= 0 && y + i <= 7 && y + i >= 0) && (imaginaryArray[x + i][y + i] == 0))
        {
            heuristic[x][y] += 1;
            imaginaryArray[x + i][y + i] = 1;
        }
        
        if ((x - i <= 7 && x - i >= 0 && y - i <= 7 && y - i >= 0) && (imaginaryArray[x - i][y - i] == 0))
        {
            heuristic[x][y] += 1;
            imaginaryArray[x - i][y - i] = 1;
        }

        //update diagonal second
        if ((x + i <= 7 && x + i >= 0 && y - i <= 7 && y - i >= 0) && (imaginaryArray[x + i][y - i] == 0))
        {
            heuristic[x][y] += 1;
            imaginaryArray[x + i][y - i] = 1;
        }
        
        if ((x - i <= 7 && x - i >= 0 && y + i <= 7 && y - i >= 0) && (imaginaryArray[x - i][y + i] == 0))
        {
            heuristic[x][y] += 1;
            imaginaryArray[x - i][y + i] = 1;
        }
        
    }


    //reset imaginary array
    for (size_t z = 0; z < ROWS; z++)
        {
            for (size_t t = 0; t < COLUMNS; t++)
            {
                if (imaginaryArray[z][t] == 1)
                {
                    imaginaryArray[z][t] = 0;
                }
                
            }
            
        }
}

void setAnotherQueen() {

    int maxValue{99};
    int moveRow{-1};
    int moveColumn{-1};

    for (size_t i = 0; i < ROWS; i++)
    {
        for (size_t j = 0; j < COLUMNS; j++)
        {
            if (heuristic[i][j] < maxValue)
            {
                maxValue = heuristic[i][j];
                moveRow = i;
                moveColumn = j;
            }
             
        }
        
    }

    if (maxValue != 99 && moveRow != -1 && moveColumn != -1)
    {
        initiateQueen(moveRow, moveColumn);
        updateImaginaryArray(moveRow, moveColumn);
        calculateCurrentHeuristic();
        counter++;
    }
    
    
}