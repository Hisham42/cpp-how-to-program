#include <iostream>

using namespace std;

int main() {



    int first{0}, second{1}, third{0};

    cout << "fibonacci(" << first << ") = " << first << endl;
    cout << "fibonacci(" << second << ") = " << second << endl;

    for (int i = 2; i < 36; i++)
    {
        
        third = first + second;
        cout << "fibonacci(" << i << ") = " << third << endl;

        first = second;
        second = third;

    }
    
}