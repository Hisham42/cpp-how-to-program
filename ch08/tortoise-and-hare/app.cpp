#include <iostream>
#include <array>
#include <random>

using namespace std;

const int ARRAYSIZE = 70;
void printArray(char *);
void moveTortoise(int *x, char *y);
void moveHare(int *z, char* a);
int tPlace{0};
int hPlace{0};
bool initiationStop{false};

int main() {

    default_random_engine engine(static_cast<unsigned int>(time(0)));
    uniform_int_distribution <unsigned int> randomInt(1,50);
    int randomNumber{0};
    int x = randomInt(engine);

    char pathT[ARRAYSIZE];
    char pathH[ARRAYSIZE];

    pathT[0] = 'T';
    pathH[0] = 'H';

    cout << "BANG !!!!!\nAND THEY'RE OFF !!!!!" << endl;

    printArray(pathT);
    printArray(pathH);


    while (pathT[ARRAYSIZE - 1] != 'T' && pathH[ARRAYSIZE - 1] != 'H')
    {
        randomNumber = randomInt(engine);
        
        moveTortoise(&randomNumber, pathT);
        
        moveHare(&randomNumber, pathH);


        if (tPlace == hPlace)
        {
            cout << "OUCH!!!" << endl;
        }
        
        
        printArray(pathT);
        printArray(pathH);

        
    }

    if (pathT[ARRAYSIZE - 1] == 'T' )
    {
        cout << "TORTOISE WINS!!! YAY!!!" << endl;
    }
    else if (pathH[ARRAYSIZE - 1] == 'H')
    {
        cout << "Hare wins. Yuck." << endl;
    }
    else if (pathT[ARRAYSIZE - 1] != 'T' && pathH[ARRAYSIZE - 1] != 'H')
    {
        cout << "It's a tie." << endl;
    }
    
    
    

}

void moveTortoise(int *randomN, char* path) {

    char *tortoisePtr{nullptr};
    

    for (size_t i = 0; i < ARRAYSIZE; i++)
    {
        if (path[i] == 'T')
        {
            tPlace = i;
            tortoisePtr = path + i;
            break;
        }
        
    }

   cout << *randomN << endl;
    
    //Fast plod
    if (*randomN >= 1 && *randomN <=25)
    {
        if (tortoisePtr + 3 > path + ARRAYSIZE - 1)
        {
            path[ARRAYSIZE - 1] = 'T';
            *tortoisePtr = '\0';
            tortoisePtr = nullptr;
        }
        else 
        {
            *(tortoisePtr + 3) = 'T';
            *tortoisePtr = '\0';
            tortoisePtr = nullptr;
        }
    }
    
    
    //Slip
    else if (*randomN >= 26 && *randomN <=33)
    {
        int x{0};
        for (size_t i = 0; i < ARRAYSIZE; i++)
        {
            if (path[i] == 'T')
            {
                x = i;
            }
            
        }
        if (x == 0)
        {
            /* do nothing */
        }
        
        
        else if (x > 0 && x < 7)
        {
            *path = 'T';
            *tortoisePtr = '\0';
            tortoisePtr = nullptr;
        }

        else if (x >= 7)
        {
            *(tortoisePtr - 6) = 'T';
            *tortoisePtr = '\0';
            tortoisePtr = nullptr;
        }
 
    }

    //Slow plod
    else if (*randomN >= 34 && *randomN <=50)
    {
        if (tortoisePtr + 3 > path + ARRAYSIZE - 1)
        {
            path[ARRAYSIZE - 1] = 'T';
            *tortoisePtr = '\0';
            tortoisePtr = nullptr;
        }
        else
        {
            *(tortoisePtr + 1) = 'T';
            *tortoisePtr = '\0';
            tortoisePtr = nullptr;
        }
        
    }


}

void printArray(char * path) {

    for (size_t i = 0; i < ARRAYSIZE / 2; i++)
    {
        cout << "| " << path[i] << " ";
    }

    cout << endl;

    for (size_t i = ARRAYSIZE / 2 + 1; i < ARRAYSIZE; i++)
    {
        cout << "| " << path[i] << " ";
    }

    cout << endl;
    

}

void moveHare(int *randomN, char* path) {

   
    
    char *harePtr{nullptr};
    //sleep
    for (size_t i = 0; i < ARRAYSIZE; i++)
    {
        if (path[i] == 'H')
        {
            hPlace = i;
            harePtr = path + i;
            break;
        }
        
    }


    //Big hop
    if (*randomN >= 20 && *randomN <=27)
    {
        if (harePtr + 11 > path + ARRAYSIZE - 1)
        {
            path[ARRAYSIZE - 1] = 'H';
            *harePtr = '\0';
            harePtr = nullptr;
        }
        else 
        {
            *(harePtr + 11) = 'H';
            *harePtr = '\0';
            harePtr = nullptr;
        }
    }

    //Big slip
    else if (*randomN >= 28 && *randomN <=35)
    {
        int y{0};
        for (size_t i = 0; i < ARRAYSIZE; i++)
        {
            if (path[i] == 'H')
            {
                y = i;
            }
            
        }
        if (y == 0)
        {
            /* do nothing */
        }
        
        
        else if (y > 0 && y < 10)
        {
            *path = 'H';
            *harePtr = '\0';
            harePtr = nullptr;
        }

        else if (y >= 10)
        {
            *(harePtr - 9) = 'H';
            *harePtr = '\0';
            harePtr = nullptr;
        }
    }

    //small hop
    else if (*randomN >= 36 && *randomN <=45)
    {
        if (harePtr + 1 > path + ARRAYSIZE - 1)
        {
            path[ARRAYSIZE - 1] = 'H';
            *harePtr = '\0';
            harePtr = nullptr;
        }
        else 
        {
            *(harePtr + 1) = 'H';
            *harePtr = '\0';
            harePtr = nullptr;
        }
    }

    //small slip
    else if (*randomN >= 46 && *randomN <=50)
    {
        int y{0};
        for (size_t i = 0; i < ARRAYSIZE; i++)
        {
            if (path[i] == 'H')
            {
                y = i;
            }
            
        }
        if (y == 0)
        {
            /* do nothing */
        }
        
        
        else if (y > 0 && y < 3)
        {
            *path = 'H';
            *harePtr = '\0';
            harePtr = nullptr;
        }

        else if (y >= 3)
        {
            *(harePtr - 2) = 'H';
            *harePtr = '\0';
            harePtr = nullptr;
        }
    }
    

    
}

