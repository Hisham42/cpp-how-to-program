#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    int count{0};
    int count2{19};
    int count3{0};

    for (size_t i = 0; i < 10; i++, count++, count3++)
    {
        
        for (size_t j = 0; j <= count; j++)
        {
            cout << "*";
        }

        for (size_t k = 0; k <= count2; k++)
        {
            
            cout << " ";
            
        }

        for (size_t l = 0; l <= count3; l++)
        {
            cout << "*";
        }

        cout << "\n";
        count2 -= 2;
          
    }

    
    
}