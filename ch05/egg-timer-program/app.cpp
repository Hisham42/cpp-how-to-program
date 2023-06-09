#include <iostream>

using namespace std;

int main() {

    int count2{0}, count1{7};

    for (size_t i = 0; i < 9; i++)
    {
        if (i == 0 || i == 8)
        {
            for (size_t j = 0; j < 9; j++)
            {
                cout << "#";
            }
            
        }
        else
        {
            
            cout << "#";    
            

            for (size_t k = 0; k < count2; k++)
            {
                cout << " ";
            }
            

            for (size_t l = 0; l < count1; l++)
            {
                cout << "*";
            }

            for (size_t m = 0; m < count2; m++)
            {
                cout << " ";
            }

            

            
            cout << "#";
            
            
        }
        
        cout << "\n";

        if (i >= 1 && i <= 3)
        {
            count1 -= 2;
            count2++;
        }
        if (i >= 4 && i <=8)
        {
            count1 += 2;
            count2--;
        }

        
        
        
        
    }
    
}