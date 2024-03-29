#include "Tree.h"
#include "Queue.h"
#include <vector>
#include <chrono>

int main() {

    /*
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

   
   

    Tree<int> alpha(20);
    alpha.insert(28);
    alpha.insert(23);
    alpha.insert(6);
    alpha.insert(100);
    alpha.insert(27);
    alpha.insert(18);
    alpha.insert(11);
    alpha.insert(28);
    alpha.insert(92);
    alpha.insert(42);
    alpha.insert(2);
    alpha.insert(33);
    alpha.insert(45);
    alpha.insert(87);

    alpha.inOrderTraversal();
    std::cout << alpha.depth() << std::endl;
    std::cout << alpha.search(87)->value << std::endl;

    
      */

    Tree<int> tree(49);
    tree.insert(28);
    tree.insert(83);
    tree.insert(18);
    tree.insert(40);
    tree.insert(11);
    tree.insert(19);
    tree.insert(32);
    tree.insert(44);
    tree.insert(71);
    tree.insert(97);
    tree.insert(69);
    tree.insert(72);
    tree.insert(92);
    tree.insert(99);

    tree.inOrderTraversal();
    tree.outputTree(5);    

    tree.levelOrderTraversal();

 



    


}

    