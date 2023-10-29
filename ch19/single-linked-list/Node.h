#ifndef NODE_H
#define NODE_H

#include <iostream>

template<typename T>
class Node
{

public:

    T value;
    Node<T>* nextNode;
    
    Node(T c) : value(c) {}
    Node() : value(T()), nextNode(nullptr) {}

};

#endif
