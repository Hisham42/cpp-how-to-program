// TreeNode definition
#ifndef TREENODE_H
#define TREE_H

template<typename T>
class TreeNode {
public:
    TreeNode* leftPtr{nullptr}; // pointer to left sub-tree
    T value;
    TreeNode* rightPtr{nullptr}; // pointer to right sub-tree
    TreeNode(const T& d=0) : value(d) {} // constructor

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