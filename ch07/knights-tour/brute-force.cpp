#include <iostream>
#include <iomanip>
#include <array>
#include <random>
#include <ctime>

const int ROWS = 8;
int MOVES = 63;
const int COLUMNS = 8;

int chessBoard[ROWS][COLUMNS];

const int HORIZONTAL [8] = {2, 1, -1, -2, -2, -1, 1, 2};
const int VERTICAL   [8] = {-1, -2, -2, -1, 1, 2, 2, 1};

int tours [1000];

int currentRow{0};
int currentColumn{0};
int counter{1};

const int arrayNumb = 9999999;

int storage[arrayNumb];


using namespace std;

void displayChessboard();
void moveKnight(int number);
void initiateKnight(int a, int b);
void initializeArray();
void sortArray();




int main() {

    default_random_engine engine(static_cast<unsigned int>(time(0)));

    uniform_int_distribution <unsigned int> randomInt(0, 8);
    uniform_int_distribution <unsigned int> randomNum(0, 7);
    

    for (int t = 0; t < arrayNumb; t++)
    {

    
        initiateKnight(0, 0);

        for (size_t i = 1; i < MOVES + 1; i++)
        {
            moveKnight(randomInt(engine));
            
        }

   
        displayChessboard();  
    
    cout << counter << endl;
    storage[t] = counter;

    if (counter == 64)
    {
        break;
    }
    

    }


    sortArray();
    cout << storage[0] << endl;
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
        
        
    }
    else
    {
    
        currentColumn -= HORIZONTAL[number];
        currentRow -= VERTICAL[number];
        
       
    }

   

}

void initiateKnight(int a, int b){
    currentColumn = a;
    currentRow = b;
    initializeArray();
    counter = 1;
    chessBoard[currentRow][currentColumn] = counter;
    
    
}


void initializeArray() {

    for (size_t i = 0; i < ROWS; i++)
    {
        for (size_t j = 0; j < COLUMNS; j++)
        {
            /* code */
            chessBoard[i][j] = 0;
        }
        
    }

    
    
    
}


void sortArray() {

    int x;
    for (size_t i = 0; i < arrayNumb; i++)
    {
        for (size_t j = 0; j < arrayNumb; j++)
        {
            if (storage[i] > storage[j])
            {
                x = storage[i];
                storage[i] = storage[j];
                storage[j] = x;
            }
            
        }
        
        
    }
    

}



