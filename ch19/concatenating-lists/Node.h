#ifndef NODE_H
#define NODE_H

#include <iostream>

class Node
{
private:
    /* data */
public:

    char value{'\0'};
    Node* nextNode{nullptr};
    
    Node(char c = '\0') : value(c), nextNode(nullptr) {}

    ~Node() {
        
    }
};

#endif
