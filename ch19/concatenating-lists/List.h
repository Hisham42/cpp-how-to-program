#ifndef LIST_H
#define LIST_H

#include "Node.h"

class List : private Node
{
private:
    Node* firstNode;
    Node* lastNode;
    
public:
    List(char c='\0')
    : firstNode(new Node(c)), lastNode(firstNode) {}

    ~List() {
        Node* temp;
        
        while (firstNode != nullptr)
        {
            temp = firstNode;
            firstNode = firstNode->nextNode;
            delete temp;
            temp = nullptr;

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

            while (currentPtr != lastNode)
            {
                std::cout << currentPtr->value << " ";
                currentPtr = currentPtr->nextNode;
            }
            std::cout << lastNode->value << std::endl;
            
        }
        else
        {
            std::cout << "List is empty" << std::endl;
        }
        
    }


    friend List concatenate(const List& l1, const List& l2) {
        List l3;

        //copy l1
        Node* temp{nullptr};
        char c;
        temp = l1.firstNode;
        while (temp!= nullptr)
        {
            c = temp->value;
            l3.insertChar(c);
            temp = temp->nextNode;
        }
        temp = l2.firstNode;
        while (temp!= nullptr)
        {
            c = temp->value;
            l3.insertChar(c);
            temp = temp->nextNode;
        }
        
        return l3;
        
    }

    //function spilt, takes int indicating the split point
    //and a list to manipulate
    //it will retrun a new list with the remaing nodes
    friend List split(int splittingPoint, List& li) {
        //check if the splitting point is valid or not
        List splittedList;

        Node* tempPtr = li.firstNode;
        Node* newLast;
        int counter{1};

        while (splittingPoint != counter)
        {   
            newLast = tempPtr;
            tempPtr = tempPtr->nextNode;
            counter++;
        }

        
        Node* assistant = tempPtr;

        while (tempPtr != nullptr)
        {
            char c = tempPtr->value;
            splittedList.insertChar(c);
            tempPtr = tempPtr->nextNode;
        }

        tempPtr = newLast;
        
        li.lastNode = newLast;
        return splittedList;
        
        
    }

};


#endif