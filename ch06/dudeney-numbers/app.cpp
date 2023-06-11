#include <iostream>
#include <math.h>

using namespace std;

int main(){

    //19683 = 273 and 1 + 9 + 6 + 8 + 3 = 27
    bool x{true}, y{true}, z{true};
    int i{0};
    int x1, x2, x3, x4, x5;
    int y1, y2, y3, y4, y5;
    
    while (true)
    
    {
        x1 = i % 10;
        y1 = i / 10;

        x2 = y1 % 10;
        y2 = y1 / 10;

        x3 = y2 % 10;
        y3 = y2 / 10;

        x4 = y3 % 10;
        y4 = y3 / 10;

        x5 = y4 % 10;
        y5 = y4 / 10;


        if (pow((x1 + x2 + x3 + x4 + x5), 3) == i)
        {
            cout << "\n" << i;
            
        }
        i++;
        
    }

    cout << endl;
    
}