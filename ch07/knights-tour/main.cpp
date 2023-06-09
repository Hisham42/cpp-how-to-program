#include <iostream>
#include <iomanip>
#include <array>

const int ROWS = 8;
int MOVES = 63;
const int COLUMNS = 8;

int chessBoard[ROWS][COLUMNS];
int nextAccessibility(int value);
const int HORIZONTAL [8] = {2, 1, -1, -2, -2, -1, 1, 2};
const int VERTICAL   [8] = {-1, -2, -2, -1, 1, 2, 2, 1};

int accessabilityHeuristic [8][8] = {
    {2, 3, 4, 4, 4, 4, 3, 2},
    {3, 4, 6, 6, 6, 6, 4, 3},
    {4, 6, 8, 8, 8, 8, 6, 4},
    {4, 6, 8, 8, 8, 8, 6, 4},
    {4, 6, 8, 8, 8, 8, 6, 4},
    {4, 6, 8, 8, 8, 8, 6, 4},
    {3, 4, 6, 6, 6, 6, 4, 3},
    {2, 3, 4, 4, 4, 4, 3, 2}       
};

int currentRow{0};
int currentColumn{0};
int counter{1};

using namespace std;

void displayChessboard();
void moveKnight(int number);
void initiateKnight(int a, int b);
void displayHeuristicArray();
int accessibilityGetter(int number);
int accurateMoveNumber();
void reduceAccessibility(int row, int column);
int recursiveAccurateMove();

int main() {
    
    
    initiateKnight(0, 0);

    for (size_t i = 1; i < MOVES + 1; i++)
    {
        moveKnight(accurateMoveNumber());
        
    }
   
    displayChessboard();
    
    
    cout << "\n" << counter << endl;
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

void moveKnight(int number) {
    currentColumn += HORIZONTAL[number];
    currentRow += VERTICAL[number];

    if (currentColumn >= 0 && currentColumn <= 7 && currentRow >= 0 && currentRow <=7 && chessBoard[currentRow][currentColumn] == 0)
    {
        counter++;
        chessBoard[currentRow][currentColumn] = counter;
        reduceAccessibility(currentRow - VERTICAL[number], currentColumn - HORIZONTAL[number]);
        
    }
    else
    {
        currentColumn -= HORIZONTAL[number];
        currentRow -= VERTICAL[number];
        cout << "Move " << number << " Failed!" << endl;
    }

}

void initiateKnight(int a, int b){
    currentColumn = a;
    currentRow = b;
    chessBoard[currentRow][currentColumn] = 1;
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
            cout << setw(3) << accessabilityHeuristic[i][j];
            cout << setw(2) << " ";
        }
        cout << endl;
        
    }
    
    
}

int accessibilityGetter(int number) {
    //1
    int optionalColumn_1 = currentColumn + HORIZONTAL[number];
    int optionalRow_1 = currentRow + VERTICAL[number];
    int accessability1;

    if (optionalColumn_1 >= 0 && optionalColumn_1 <=7 && optionalRow_1 >= 0 && optionalRow_1 <= 7 && chessBoard[optionalRow_1][optionalColumn_1] == 0)
    {
        accessability1 = accessabilityHeuristic[optionalRow_1][optionalColumn_1];
    }
    else
    {
        accessability1 = 100;
    }

    return accessability1;
}

int accurateMoveNumber() {

    int options[8];
    int x;

    for (size_t i = 0; i < 8; i++)
    {
        options[i] = accessibilityGetter(i);
        
    }

    

   for (size_t i = 0; i < 8; i++)
   {
    x = 0;
    for (size_t j = 0; j < 8; j++)
    {
        if (options[i] <= options[j])
        {
            x++;
        }

        if (x == 8)
        {
            x = i;
           
            return x;
        }
        else
        {
            continue;
        }
        
        
    }
   }

    return x;

}

void reduceAccessibility(int row, int column) {
    
    
    for (size_t i = 0; i < 8; i++)
    {
        if (row + VERTICAL[i] >= 0 && row + VERTICAL[i] <= 7 && column + HORIZONTAL[i] >=0 && column + HORIZONTAL[i] <= 7)
        {
            accessabilityHeuristic[row + VERTICAL[i]][column + HORIZONTAL[i]] -= 1;
        }
        
    }
    
    
}

int nextAccessibility(int value) {

    int x = currentRow + VERTICAL[value];
    int y = currentColumn + HORIZONTAL[value];

    return accessabilityHeuristic[x][y];




}

int recursiveAccurateMove() {

    int x{accurateMoveNumber()};
    int options[8];

    for (size_t i = 0; i < 8; i++)
    {
        options[i] = accessibilityGetter(i);
        cout << options[i] << " ";
    }
    cout << "||x: " <<x << endl ;

    for (size_t i = 0; i < 8; i++)
    {
        if (i != x)
        {
            if (options[x] == options[i])
            {
                cout << "\n Accessibility Compare " << nextAccessibility(x) << " "<< nextAccessibility(i);

            }
        }
        
    }
    cout << endl;
    










    return x;
}