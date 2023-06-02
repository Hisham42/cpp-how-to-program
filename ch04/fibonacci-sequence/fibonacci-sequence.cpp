#include <iostream>
using namespace std;
/*0, 1, 1, 2, 3, 5, 8, */
int main(){
    unsigned int x{0};
    unsigned int y{1};
    unsigned int z{0};
    cout << "0, 1, ";

    while (true)
    {
        z = x + y;
        
        cout << z << ", ";

        x = y;
        y = z;

    }
    
}