#include <iostream>
#include <iomanip>
#include <array>


using namespace std;

int main() {

    //initialize array size
    int size = 10;

    //create an array
    int primeNumbers [size];

    //initiate it to 1
    for (size_t i = 0; i < size; i++)
    {
        primeNumbers[i] = 1;
    }

    //algorithm
    for (size_t j = 2; j < size; j++)
    {
        for (size_t k = j + 1; k < size; k++)
        {
            if (primeNumbers[k] == 1)
            {
                if (k % j == 0)
                {
                    primeNumbers[k] = 0;
                }
            }
            
        }
    }

    //print output

    for (size_t l = 2; l < size; l++)
    {
        if (primeNumbers[l] == 1)
        {
            cout << l << endl;
        }
        
        
    }
    
}