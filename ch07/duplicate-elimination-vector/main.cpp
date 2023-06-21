#include <iostream>
#include <vector>
#include <stdexcept>

unsigned int vectorSize = 0;

using namespace std;

int main() {
    //Read in 20 numbers,each of which is between 10 and 100,As each number is read,
    //validate it and store it in the vector only if it isn’t a duplicate of a number already read.

    //After reading all the values, display only the unique values that the user entered.

    //Provide for the “worst case” in which all 20 numbers are different. Use the smallest possible vector to solve this problem.




    vector <int> storage(vectorSize);
    
    

    for (size_t i = 0; i < 20; i++)
    {
        int reader{0};
        bool duplicate{false};

        cin >> reader;
       

        if (reader >= 10 && reader <= 100)
        {
            for (size_t j = 0; j < vectorSize; j++)
            {
                if (reader == storage[j])
                {
                    duplicate = true;
                    break;
                }
                
            }

            if (!duplicate)
            {
                storage.push_back(reader);
                vectorSize += 1;
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