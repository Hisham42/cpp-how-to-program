// Exercise 6.44: ex06_44.cpp
// What does this program do?
#include <iostream>
using namespace std;
int mystery(int, int); // function prototype

int main() {
    cout << "Enter two integers: ";
    int x{0};
    int y{0};
    cin >> x >> y;
    cout << "The result is " << mystery(x, y) << endl;
}

// Parameter b must be a positive integer to prevent infinite recursion
int mystery(int a, int b) {
    if (b > 0)
    {
    
        if (1 == b) { // base case
            return a;
        }
        else { // recursion step
            return a + mystery(a, b - 1);
        }
    }
    else if (b == 0)
    {
       return 0;
    }
    else
    {
        if (-1 == b) { // base case
            return -a;
        }
        else { // recursion step

            return -a + mystery(a, b + 1);
        }
    }

}