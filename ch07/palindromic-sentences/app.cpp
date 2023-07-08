#include <iostream>
#include <array>

using namespace std;

bool testPalindrome(char *arr, int j, int i=0);

int main() {


    char palindromicArray [] = "red roses run no risk, sir, on nurses order.";

    int size{-1};

    for (size_t i = 0; i < sizeof(palindromicArray); i++)
    {
        if (palindromicArray[i] != ' ' && palindromicArray[i] != ',' && palindromicArray[i] != '!' && palindromicArray[i] != '.')
        {
            size += 1;
        }
    }

    char eliminated[size];

    int j{0};

    for (size_t i = 0; i < sizeof(palindromicArray); i++)
    {
        if (j == size)
        {
            break;
        }
        
        if (palindromicArray[i] != ' ' && palindromicArray[i] != ',' && palindromicArray[i] != '!' && palindromicArray[i] != '.')
        {
            eliminated[j] = tolower(palindromicArray[i]);
            j++;
        }
    }
    
    if (testPalindrome(eliminated, j) == true)
    {
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }

    
}

bool testPalindrome(char *arr, int j, int i){



    if (i == j|| i == j + 1)
    {
        return true;
    }
    

    if (arr[i] == arr[j-1])
    {
        if (testPalindrome(arr, j-1, i+1))
        {
            return true;
        }
        
    }

    return false;
    
   

}