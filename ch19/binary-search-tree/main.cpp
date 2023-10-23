#include "Tree.h"
#include <vector>
#include <chrono>

int main() {
    Tree<int> tree1(12);
    

    for (size_t i = 0; i < 100000; i++)
    {
        tree1.insert(i);
    }
    

    auto start = std::chrono::high_resolution_clock::now();
    tree1.search(99999);
    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;


    std::vector<int> vector1;

    for (size_t i = 0; i < 1000000; i++)
    {
        vector1.push_back(i);
    }

    
    auto start2 = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < 1000000; i++)
    {
        if (vector1[i] == 99999) {
            std::cout << "Found in vector" << std::endl;
        }
        
    }
    auto stop2 = std::chrono::high_resolution_clock::now();

    auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(stop2 - start2);

    std::cout << "Time taken by function: " << duration2.count() << " microseconds" << std::endl;

    
    std::cout << sizeof(tree1) << std::endl;
    std::cout << sizeof(vector1) << std::endl;

    

}

    