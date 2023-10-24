#ifndef LIST_H
#define LIST_H

#include "Node.h"

template<typename T>
class List : private Node<T>
{
private:
    Node<T>* firstNode;
    Node<T>* lastNode;
    
public:
    List(T c= T())
    : firstNode(new Node<T>(c)), lastNode(firstNode) {}

    ~List() {
        Node<T>* temp;
        
        while (firstNode != nullptr)
        {
            temp = firstNode;
            firstNode = firstNode->nextNode;
            delete temp;
            temp = nullptr;

        }
        
    }

    void insert(T c) {

        if (isempty())
        {
            firstNode->value = c;
        }
        
        else
        {
            Node<T>* insertedNode = new Node<T>;
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
            Node<T>* currentPtr = firstNode;

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


    friend List<T> concatenate(const List<T>& l1, const List<T>& l2) {
        List<T> l3;

        //copy l1
        Node<T>* temp{nullptr};
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
    friend List<T> split(int splittingPoint, List<T>& li) {
        //check if the splitting point is valid or not
        List splittedList;

        Node<T>* tempPtr = li.firstNode;
        Node<T>* newLast;
        int counter{1};

        while (splittingPoint != counter)
        {   
            newLast = tempPtr;
            tempPtr = tempPtr->nextNode;
            counter++;
        }

        
        Node<T>* assistant = tempPtr;

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


    friend List<T> reverse(List<T>& li) {

        List<T> newList; // create an empty list
        Node<T>* ptr{nullptr}; // create a Ptr
        ptr = li.firstNode; // assign ptr to the targetted list

        reverseHelper(ptr, newList); // recursive function to insert reverse

        return newList;
        
    }

    friend bool reverseHelper(Node<T>* ptr, List<T>& newList) {

        // base
        if (ptr->nextNode == nullptr)
            {   
                newList.insertChar(ptr->value);         
                return true;
            }
        // recursive function
        if (reverseHelper(ptr->nextNode, newList))
        {
            newList.insertChar(ptr->value);
            return true;
        }

        return false;
    }



};


#endif