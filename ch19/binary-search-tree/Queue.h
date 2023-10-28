#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <cctype>
#include "QueueNode.h"

template<typename T>
class Queue : private QueueNode<T>
{
private:
    QueueNode<T>* head;
    QueueNode<T>* tail{nullptr};
public:

    Queue() {
        head = new QueueNode<T>();
        tail = head;
        head->next = nullptr;
        
    }
    void printHead() {
        std::cout << head->treeNode->value << " ";
    }

    QueueNode<T>* getHead() {
        return head;
    }
    void enqueue(TreeNode<T>* tree) {
        if (isempty())
        {
            head->treeNode = tree;
        }
        else
        {
            QueueNode<T>* temp = new QueueNode<T>();
            temp->treeNode = tree;
            temp->next = tail;
            tail = temp;
        }
    }

    

    void dequeue() {
        if (isempty())
        {
           
        }
        else if (head == tail && head->treeNode->value != T())
        {
            head->treeNode->value = T();
        }
        else if (tail->next == head)
        {
            QueueNode<T>* temp = tail->next;
            head = tail;
            temp = nullptr;
            delete temp;
            
            head->next == nullptr;
            
        }
        
        else {
            QueueNode<T>* temp = tail;
            
            while (temp->next->next != nullptr)
            {
                temp = temp->next;
            }

            delete head;
            head = nullptr;
            head = temp;
            head->next = nullptr;
        
        }

    }

    TreeNode<T>* queueHead() {

        if (isempty())
        {
            
        }
        
        return head->treeNode;

    }


    bool isempty() {

        if ((head == tail && head == nullptr) || (head == tail && head->treeNode == nullptr) || (head == tail && head->treeNode->value == T()))
        {
            return true;
        }
        else
            return false;
        

    }

    void print() {

        if (isempty())
        {
            
        }
        else {
            QueueNode<T>* temp = tail;
            while (temp != nullptr)
            {
                std::cout << temp->treeNode->value;
                if (temp->next != nullptr)
                {
                    std::cout << " -> ";
                }
                
                temp = temp->next;
            }
            std::cout << std::endl;
        }
    }

        
    
    
    ~Queue() {
        QueueNode<T>* temp = tail;
        QueueNode<T>* current;

        while (temp != nullptr) {
            current = temp;
            temp = temp->next;
            delete current;
        }
    }

    

};


#endif 