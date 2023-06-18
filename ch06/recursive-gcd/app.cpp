#include <iostream>
using namespace std;

int gcd(int x, int y);

int main() {

    cout << gcd(52, 48) << endl;

}

int gcd(int x, int y) {
    if (y == 0)
    {
        return x;
    }
    else
    {
        return gcd(y, x % y);
    }
    
}