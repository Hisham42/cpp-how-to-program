#include <iostream>
#include <array>
#include <random>

void swap(int& a, int& b) {
    int c = a;
    a = b;
    b = c;
}

void bubbleSort(std::array<int, 20>& arr) {
    int x = arr.size();

    for (size_t i = 0; i < arr.size(); i++)
    {
        for (size_t j = i; j < x; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
    
}

int main() {

    // generate random int
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> randomInt{10, 99}; 

    // initialize array with random items then print it
    std::array<int, 20> unsortedArray;
    for (size_t i = 0; i < 20; i++)
    {
        unsortedArray[i] = randomInt(gen);
        std::cout << unsortedArray[i];
        std::cout << " ";
    }
    std::cout << std::endl;
    
    bubbleSort(unsortedArray);

    // print the sorted array
    for (size_t i = 0; i < 20; i++)
    {
        std::cout << unsortedArray[i];
        std::cout << " ";
    }
    std::cout << std::endl;
}