// TreeNode definition
#ifndef TREENODE_H
#define TREENODE_H

template<typename T>
class TreeNode {
public:
    TreeNode* leftPtr{nullptr}; // pointer to left sub-tree
    T value;
    TreeNode* rightPtr{nullptr}; // pointer to right sub-tree
    TreeNode(const T& d) : value(d) {} // constructor
    TreeNode() : value(T()) {} // default constructor

    bool isLeaf() {
        if (leftPtr == nullptr && rightPtr == nullptr) {
            return true;
        }
        else {
            return false;
        }
        
    }
};

#endif