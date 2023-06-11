#include <iostream>

using namespace std;
void reverseDigits(int number);

int main() {
    int number{0};

    cin >> number;
    reverseDigits(number);
    cout << "\n";
}

void reverseDigits(int number){

    
    while (number != 0)
    {
        cout << number % 10;
        number /= 10;
    }
    
}