#include <iostream>
#include <array>
#include <string>

using namespace std;

void printBackward(char *arr, int arrayIndex);

//void printRecursive(char *arr, int i=0, int j=INDEX);

int main() {

    char chrArray[] = "My name is Hisham.";

    int arrayIndex = sizeof(chrArray)- 1;

    printBackward(chrArray, arrayIndex);

    cout << endl;

}

void printBackward(char *arr, int arrayIndex) {
    
    
    if (arrayIndex > 0)
    {
        cout << arr[arrayIndex - 1];
        printBackward(arr, arrayIndex - 1);
    }  

}