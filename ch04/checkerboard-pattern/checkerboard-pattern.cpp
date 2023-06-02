#include <iostream>
using namespace std;

int main() {


    unsigned int x{0};
    unsigned int counter{0};

    while(x < 8)
    {
        if (x % 2 != 0)
        {
            cout << ' ';
        }

        counter = 0;
        while (counter < 8)
        {
            
            cout << "* ";
            counter ++;
        }

        x++;
        cout << endl;
    }
}