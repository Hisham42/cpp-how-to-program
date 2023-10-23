#ifndef TREE_H
#define TREE_H

#include <iostream>
#include "TreeNode.h"

template<typename T>
class Tree : private TreeNode<T>
{
private:
    // node
    TreeNode<T>* root;

    // helper function to insert a new node
    void insertNode(T value, TreeNode<T>* n) {

        if (value < n->value) {
            /* insert left */
            if (n->leftPtr == nullptr) {
                n->leftPtr = new TreeNode(value);
            }
            else {
                n = n->leftPtr;
                insertNode(value, n);
            }
            
        }

        else if (value > n->value) {
            /* insert right */
            if (n->rightPtr == nullptr) {
                n->rightPtr = new TreeNode(value);
            }
            else {
                n = n->rightPtr;
                insertNode(value, n);
            }
        }

        else {
            std::cout << "Duplicate Value" << std::endl;
        }
        
         
    }
    void inOrderHelper(TreeNode<T>* n) {

        if (n->isLeaf())
        {
            std::cout << n->value << " ";
        }
        else {
            if (n->leftPtr != nullptr)
            {
                inOrderHelper(n->leftPtr);
            }
            
            std::cout << n->value << " ";

            if (n->rightPtr != nullptr)
            {
                inOrderHelper(n->rightPtr);
            }
            
        }

    }

    void deleteHelper(TreeNode<T>* n) {

        if (n->isLeaf())
        {
            delete n;
        }
        else {
            if (n->leftPtr != nullptr)
            {
                deleteHelper(n->leftPtr);
            }

            if (n->rightPtr != nullptr)
            {
                deleteHelper(n->rightPtr);
            }

            delete n;   
        }
    }

    bool searchHelper(T valuePassed, TreeNode<T>* n) {

        if (n != nullptr)
        {
            if (n->value == valuePassed)
            {
                std::cout << valuePassed << " was found!" << std::endl;
                return true;
            }
            else if (n->value > valuePassed){
                searchHelper(valuePassed, n->leftPtr);
            }

            else if (n->value < valuePassed) {
                searchHelper(valuePassed, n->rightPtr);
            }

            return true;
            
        }
        else {
            return false;
        }
        
    }

    
public:
    // constructor
    Tree(T rootValue) {
        root = new TreeNode<T>(rootValue); // this will grant a node space in the heap for the *
    }

    // insert node
    void insert(T value) {
        insertNode(value, root);   
    }

    void inOrderTraversal() {
        inOrderHelper(root);
        std::cout << std::endl;
    }
    // destructor
    ~Tree() {
        deleteHelper(root);
    }

    void search(int valuePassed) {
        if (!searchHelper(valuePassed, root))
        {
            std::cout << valuePassed << " was not found!" << std::endl;
        }
    }
};


#endif
