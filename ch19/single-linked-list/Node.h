#ifndef NODE_H
#define NODE_H

#include <iostream>

template<typename T>
class Node
{

public:

    T value{'\0'};
    Node<T>* nextNode{nullptr};
    
    Node(T c = '\0') : value(c) {}

};

#endif
