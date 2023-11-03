// Fig. 20.2: LinearSearch.cpp
// Linear search of an array.
#include <iostream>
#include <array>
#include <random>
#include <string>
using namespace std;

// compare key to every element of array until location is     
// found or until end of array is reached; return location of  
// element if key is found or -1 if key is not found           
                         
int linearSearch(int*& items, int size, const int& key) {
   for (size_t i{0}; i < size; ++i) {                
      if (key == items[i]) { // if found,                    
         return i; // return location of key                 
      }                                                      
   }                                                         

   return -1; // key not found                               
}                                                            

int main(int argc, char* argv[]) {

    if (argc < 2)
    {
        return 1;
    }
    

    int n = stoi(argv[1]);

    std::random_device rd;  // Obtain a random number from hardware
    std::mt19937 gen(rd()); // Seed the generator
    
    std::uniform_int_distribution<int> distrib(1, n); // Define the range [1, 4]

    int* arr = new int[n];
    
    for (size_t i{0}; i < n; ++i) {
        arr[i] = int(distrib(gen)); // create some data
    }
    
    int searchKey = stoi(argv[2]);

    // attempt to locate searchKey in arrayToSearch
    int element{linearSearch(arr, n, searchKey)};

    // display results
    if (element != -1) {
        cout << "Found value in element " << element << endl;
    }
    else {
        cout << "Value not found" << endl;
    }

} 

