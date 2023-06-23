#include <array>
#include <iostream>

using namespace std;
void displayArray(int items[], int sizeOfItems);
void displayArray2(array <int, 3> items);

int main() {

   

    int arr1[2] = {1, 2};
    array <int, 3> arr2 = {3, 4, 5};


    displayArray(arr1, 2);
    displayArray2(arr2);


}

void displayArray(int items[], int sizeOfItems) {
    for (size_t i = 0; i < sizeOfItems; i++)
    {
        cout << items[i] << endl;
    }

}

void displayArray2(array <int, 3> items) {
    
    for (size_t i = 0; i < items.size(); i++)
    {
        cout << items[i] << endl;
    }
}