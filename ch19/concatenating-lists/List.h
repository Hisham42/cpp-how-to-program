#ifndef LIST_H
#define LIST_H

#include "Node.h"

class List : private Node
{
private:
    Node* firstNode = new Node;
    Node* lastNode;
public:
    List(char c='\0') {
        
        firstNode->value = c;
        lastNode = firstNode;
    }

    ~List() {
        Node* temp;
        
        while (firstNode != nullptr)
        {
            temp = firstNode;
            firstNode = firstNode->nextNode;
            delete temp;

        }
        
    }

    void insertChar(char c) {

        if (isempty())
        {
            firstNode->value = c;
        }
        
        else
        {
            Node* insertedNode = new Node;
            (*insertedNode).value = c;
            insertedNode->nextNode = nullptr;
            (*lastNode).nextNode = insertedNode;
            lastNode = insertedNode;

        }

        

    }


    bool isempty() {

        if (firstNode == lastNode && firstNode->value == '\0')
        {
            return true;
        }
        else
            return false;
        
    }

    void print() {

        if (!isempty())
        {
            Node* currentPtr = firstNode;

            while (currentPtr != nullptr)
            {
                std::cout << currentPtr->value << " ";
                currentPtr = currentPtr->nextNode;
            }
            std::cout << std::endl;
            
        }
        else
        {
            std::cout << "List is empty" << std::endl;
        }
        
    }


    friend void concatenate(const List& l1, const List& l2) {
        List* l3 = new List;

        //copy l1
        Node* temp{nullptr};
        char c;
        temp = l1.firstNode;
        while (temp!= nullptr)
        {
            c = temp->value;
            l3->insertChar(c);
            temp = temp->nextNode;
        }
        temp = l2.firstNode;
        while (temp!= nullptr)
        {
            c = temp->value;
            l3->insertChar(c);
            temp = temp->nextNode;
        }
        
        l3->print();
        

        delete l3;
    }



};


#endif