#ifndef NODE_H
#define NODE_H

#include <iostream>

class Node
{

public:

    char value{'\0'};
    Node* nextNode{nullptr};
    
    Node(char c = '\0') : value(c) {}

};

#endif
