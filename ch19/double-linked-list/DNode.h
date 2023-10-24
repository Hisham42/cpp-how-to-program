#ifndef DNODE_H
#define DNODE_H

#include <iostream>

template<typename T>
class DNode
{

public:

    DNode<T>* prev;
    T value;    
    DNode<T>* next;

    explicit DNode(const T& data) : value(data), prev(nullptr), next(nullptr) {}
    DNode() : value(T()), prev(nullptr), next(nullptr) {} // default constructor

};

#endif