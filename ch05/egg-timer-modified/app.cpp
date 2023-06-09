#include <iostream>

using namespace std;

int main() {

    int height{0};
    

    while (true)
    {
        cout << "Please enter the height: ";
        cin >> height;
        if (height % 2 != 0)
        {
            break;
        }
        
    }
    
    

    int count2{0}, count1{height - 2};

    for (size_t i = 0; i < height; i++)
    {
        if (i == 0 || i == height - 1)
        {
            for (size_t j = 0; j < height; j++)
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

        if (i >= 1 && i <= height / 2 - 1)
        {
            count1 -= 2;
            count2++;
        }
        if (i >= height / 2 && i <=height - 1)
        {
            count1 += 2;
            count2--;
        }

        
        
        
        
    }
    
}