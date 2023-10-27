#include "Tree.h"
#include <sstream>

int main() {

    std::string ahmed = "Ahmed is the biggest one in the family.";
    std::istringstream iss(ahmed);

    Tree<std::string> treeString;


    std::string word;
    while (iss >> word) {
        treeString.insert(word);
    }


    treeString.inOrderTraversal();
    treeString.preOrderTraversal();
    treeString.postOrderTraversal();


    Tree<int> treeInt;
    treeInt.insert(10);
    treeInt.insert(5);
    treeInt.insert(1);
    treeInt.insert(7);
    treeInt.insert(6);
    treeInt.insert(14);
    treeInt.insert(12);
    treeInt.insert(16);

    treeInt.inOrderTraversal();
    treeInt.preOrderTraversal();
    treeInt.postOrderTraversal();
}

    