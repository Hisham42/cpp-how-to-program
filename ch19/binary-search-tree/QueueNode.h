#ifndef QUEUENODE_H
#define QUEUENODE_H
#include "TreeNode.h"
template<typename T>
class QueueNode : private TreeNode<T>
{
public:
    TreeNode<T>* treeNode;
    
    QueueNode<T>* next;

    QueueNode() {
        treeNode = nullptr; 
        next = nullptr;
        }

};



#endif