#include <iostream>
#include <array>

const unsigned int ARRAY_SIZE = 20;

using namespace std;

int main() {
    //Read in 20 numbers,each of which is between 10 and 100,As each number is read,
    //validate it and store it in the array only if it isn’t a duplicate of a number already read.

    //After reading all the values, display only the unique values that the user entered.

    //Provide for the “worst case” in which all 20 numbers are different. Use the smallest possible array to solve this problem.




    array <int, ARRAY_SIZE> storage;
    
    

    for (size_t i = 0; i < ARRAY_SIZE; i++)
    {
        int reader{0};
        bool duplicate{false};

        cin >> reader;
       

        if (reader >= 10 && reader <= 100)
        {
            for (size_t j = 0; j < ARRAY_SIZE; j++)
            {
                if (reader == storage[j])
                {
                    duplicate = true;
                    break;
                }
                
            }
            if (!duplicate)
            {
                storage[i] = reader;
            }
            
            
        }
        
    }


    cout << "\nUnique Values:" << endl;

    for (auto &&item : storage)
    {
        if (item >= 10 && item <= 100)
        {
            cout << item << endl;
        }
         
    }
    
    

}