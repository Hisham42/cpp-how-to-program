#include <iostream>

using namespace std;

int main() {

    int i{0}, j{3};
    double bi{4.0};

    while (true)
    {
        if (i > 131000)
        {
            break;
        }

        if (i % 2 == 0)
        {
            bi += -4.0/j;
        }
        else
        {
            bi += 4.0/j;
        }
        
        j += 2;
        i++;
    }

    cout << bi << endl;
    
}