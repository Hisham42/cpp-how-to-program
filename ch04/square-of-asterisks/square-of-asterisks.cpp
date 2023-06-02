#include <iostream>
using namespace std;

int main() {

    unsigned int size{0};
    unsigned int counter{0};
    unsigned int whiteSpace{0};

    cout << "Please Enter asterisks size: ";
    cin >> size;
    
    while (counter < size)
    {
        cout << "*";
        counter++;
    }
    cout << "\n";
    
    
    counter = 0;
    while (counter < size -2)
    {
        whiteSpace = 0;
        cout << "*";


        while (whiteSpace < size - 2)
        {
            cout << " ";
            whiteSpace++;
        }
        

        cout << "*";

        counter++;
        cout << "\n";
        
    }
    
    
    
    counter = 0;
    while (counter < size)
    {
        cout << "*";
        counter++;
    }

    cout << "\n";





}