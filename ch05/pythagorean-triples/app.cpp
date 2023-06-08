#include <iostream>
#include <math.h>
#include <iomanip>


using namespace std;

int main() {

    cout << setw(7) << "Side 1" << setw(4) << "Side 2" << setw(4) << "Hypotenuse" << endl;

    for (size_t i = 1; i <= 500; i++)
    {
        for (size_t j = 1; j <= 500; j++)
        {
            for (size_t k = 1; k <= 500; k++)
            {
                if (pow (k, 2) == (pow(i, 2) + pow(j, 2)))
                {
                    cout << setw(7) << i << setw(7) << j << setw(7) << k << endl;
                }
                
            }
            
        }
        
    }
    
}