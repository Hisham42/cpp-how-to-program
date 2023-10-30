#ifndef INDEXNODE_H
#define INDEXNODE_H
#include <string>

class Node
{
public:
    std::string nodeValue;
    Node* nextNode;
    Node() : nodeValue(std::string()), nextNode(nullptr) {}
};

class IndexNode : public Node
{
public:
    char indexValue;
    IndexNode* nextIndex;
    Node* indexFirstNode;
    IndexNode() : indexValue(char()), nextIndex(nullptr), indexFirstNode(nullptr) {}
};

#endif