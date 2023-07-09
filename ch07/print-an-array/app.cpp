#include <iostream>
#include <array>
using namespace std;


const int INDEX = 8;

void printRecursive(char *arr, int i=0, int j=INDEX);

int main() {


    char printArray[INDEX] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

    printRecursive(printArray, 0, 8);


}

void printRecursive(char *arr, int i, int j) {

    if (i < j)
    {
        cout << arr[i] << endl;
        printRecursive(arr, i + 1, j);
    }
    

}