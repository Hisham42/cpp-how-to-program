#include <iostream>
#include <fstream>

int main() {

    std::string a[] = {"ELEPHANT", "DOG", "CAT", "LION", "TURTLE", "COW", "HORSE", "DOLPHIN"};
    const int arraySize = 8;
    
    int order[arraySize];

    int value{1};

    for (size_t i = 0; i < a->size(); i++)
    {
        value = 1;

        for (size_t j = 0; j < a->size(); j++)
        {
            if (a[i].compare(a[j]) > 0 && i != j)
            {
                value++;
            }
            
        }
        order[i] = value;
        
    }


    int maxValue = arraySize;
    while (maxValue > 0)
    {

        for (size_t i = 0; i < a->size(); i++)
        {
            if (order[i] == maxValue)
            {
                std::cout << a[i] << std::endl;
            }
            
        }
        maxValue--;

    }
}