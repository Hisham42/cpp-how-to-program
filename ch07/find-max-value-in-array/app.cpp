#include <iostream>
#include <array>
#include <string>

using namespace std;

int recursiveMaxValue (int *arr, int index, int i=0);

int main() {

    int arrInt [] = {1, 9, 4, 7, 6};
    int index = end(arrInt) - begin(arrInt);
    recursiveMaxValue(arrInt, index);

    cout << recursiveMaxValue(arrInt, index) << endl;

}

int recursiveMaxValue (int *arr, int index, int i) {

    if (i < index)
    {
        if (arr[i] > recursiveMaxValue(arr, index, i + 1))
        {
            return arr[i];
        }
        else
        {
            return recursiveMaxValue(arr, index, i + 1);
        }
    }
    
    else
    {
        return arr[i-1];
    }
}


