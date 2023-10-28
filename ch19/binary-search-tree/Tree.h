#ifndef TREE_H
#define TREE_H

#include <iostream>
#include "TreeNode.h"
#include "Queue.h"

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

    void searchHelper(T valuePassed, TreeNode<T>*& n, TreeNode<T>*& temp) {

        if (n->value == valuePassed)
        {
            temp = n;
        }

        if (n->leftPtr !=nullptr)
        {
            searchHelper(valuePassed, n->leftPtr,  temp);
        }

        if (n->rightPtr !=nullptr)
        {
            searchHelper(valuePassed, n->rightPtr,  temp);
        }

        
        
    }

    void depthHelper(TreeNode<T>* n, int depthValue, int& l) {

        
        // check root
        // does it have left or right 
        if (n->isLeaf())
        {
            if (l < depthValue)
            {
                l = depthValue;
            }
            
        }
        else 
        {   
            if (n->leftPtr != nullptr)
            {
                depthHelper(n->leftPtr, depthValue + 1, l);
            }

            if (n->rightPtr != nullptr)
            {
                depthHelper(n->rightPtr, depthValue + 1, l);
            }
        }
        
        

    }    

public:
    // constructor
    Tree(T rootValue) {
        root = new TreeNode<T>(rootValue); // this will grant a node space in the heap for the *
    }
    Tree() {
        root = new TreeNode<T>(T()); // this will grant a node space in the heap for the *
    }

    // insert node
    void insert(T value) {
        if (root->value == T())
        {
            root->value = value;
        }
        else
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

    TreeNode<T>* search(int valuePassed) {

        TreeNode<T>* temp{nullptr};
        searchHelper(valuePassed, root, temp);
        return temp;
    }

    int depth() {
        int level{0};
        depthHelper(root, 1, level);
        return level;
    }

    TreeNode<T>* getRoot() {
        return root;
    }

    void levelOrderTraversal() {
        Queue<T> queue;
        TreeNode<T>* temp = getRoot();
        queue.enqueue(temp);
        while (!queue.isempty())
        {
            queue.printHead();

            if (temp->leftPtr != nullptr)
            {
                queue.enqueue(temp->leftPtr);
            }
            if (temp->rightPtr != nullptr)
            {
                queue.enqueue(temp->rightPtr);
            }
            
            queue.dequeue();

            if (queue.getHead()->treeNode != nullptr)
            {
                temp = queue.getHead()->treeNode;
            }
            
            

        }
        std::cout << std::endl;
        
    }

    

};


#endif
