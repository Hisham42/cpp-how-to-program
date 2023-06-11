#include <iostream>

using namespace std;

int GCDCalculator(int number_1, int number_2);

int main() {

    int x{0}, y{0};

    cin >> x;
    cin >> y;


    
    cout << GCDCalculator(x, y) << "\n";
    
    
    

}

int GCDCalculator(int number_1, int number_2) {

    int z{0};

    for (int i = number_1; i >= 1; i--)
    {
        if (number_1 % i == 0)
        {
            if (number_2 % i == 0)
            {
                z = i;
                break;
                
            }
            
            
        }
        
    }

    return z;

    
}