#include <iostream>

using namespace std;

void discMover(int n, char fromPeg, char toPeg, char usingPeg );

int main() {

    discMover(50, 'S', 'D', 'A');

}

void discMover(int n, char A, char C, char B ) {
    
    if (n == 0)
    {
        
    }
    
    if (n == 1)
    {
        cout << A << " >> " << C << endl;
    }
    else
    {
        discMover(n-1, A, B, C);
        cout << A << " >> " << C << endl;
        discMover(n-1, B, C, A);
    }
}