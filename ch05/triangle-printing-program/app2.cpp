/*  for rows 10
        for columns 10 to 0
*/


#include <iostream>

using namespace std;

int main() {

    int count{9};

    for (size_t i = 0; i < 10; i++, count--)
    {
        
        for (size_t j = 0; j <= count; j++)
        {
            cout << "*";
        }

        cout << "\n";
          
    }
    
}