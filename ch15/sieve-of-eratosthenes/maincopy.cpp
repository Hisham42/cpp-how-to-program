// use bitset >> display all prime numbers 2-1023
// enter number to detemine if it is a prime or not
#include <iostream>
#include <bitset>
#include <deque>

using namespace std;

int main() {

    //initialize array size
    const size_t size = 100;

    //create a bit size
    bitset<size> a;

    //initiate it to 1


    for (size_t i = 0; i < size; i++)
    {
        a[i] = 1;
    }

    //algorithm
    for (size_t j = 2; j < size; j++)
    {
        for (size_t k = j + 1; k < size; k++)
        {
            if (a[k] == 1)
            {
                if (k % j == 0)
                {
                    a[k] = 0;
                }
            }
        }
    }

    //print output

    for (size_t l = 2; l < size; l++)
    {
        if (a[l] == 1)
        {
            cout << l << "\n";
        }      
    }

    // enter a number to check if Prime or not
    int prime{0}, prime2{0};
    cout << "Enter a number: " << "\n";
    cin >> prime;
    prime2 = prime;
    deque<int> li;
    if (a[prime] == true )
    {
        cout << "Is Prime" << "\n";
    }
    else
    {
        cout << "Is not Prime" << endl;
        

        for (int i = prime - 1; i > 1; )
        {
            if (a[i] != 0 && prime % i == 0)
            {
                li.push_front(i);
                prime /= i;
                
                
            }
            else 
            {
                i--;
            }
            
        }
    }

    cout << "The unique prime factorization of " << prime2 << " is: ";

    for (auto ite = li.begin(); ite != li.end(); ite++)
    {
        if (ite == li.end() - 1)
        {
            cout << *ite << endl;
        }
        else
        {
            cout << *ite << " * ";
        }
        
        
    }
    


}