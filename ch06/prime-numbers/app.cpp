#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(int number);

int main() {

    for (int i = 2; i <= 10000; i++)
    {
        if (isPrime(i))
    {
        cout << "Number " << i << " is prime." << endl;
    }
    
    }
    
}


bool isPrime(int number){
    
    int j{0};

    if (number % 2 == 0 && number != 2)
    {
        return false;
    }
    
    else {

        for (int i = 2; i < sqrt(number); i++)
        {
            if (number % i == 0)
            {
                j++;
            }
        }

        if (j == 0)
        {
            return true;
        }
        else
            return false;
    }      
}