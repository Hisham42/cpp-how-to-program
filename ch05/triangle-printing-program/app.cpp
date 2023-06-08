/*  for rows 10
        for columns 1 to 10
*/


#include <iostream>

using namespace std;

int main() {

    int count{0};

    for (size_t i = 0; i < 10; i++, count++)
    {
        
        for (size_t j = 0; j <= count; j++)
        {
            cout << "*";
        }

        cout << "\n";
          
    }
    
}