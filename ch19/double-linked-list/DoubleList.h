#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include "DNode.h"

template<typename T>
class DoubleList : public DNode<T> 
{
private:
    DNode<T>* start;
    DNode<T>* end;
public:
    // consructor
    DoubleList(T value) {
        start = new DNode(value);
        start->next = nullptr;
        start->prev = nullptr;
        end = start;
    }

    //insert

    void insert(T value) {
        
        end->next = new DNode(value);
        DNode<T>* temp = end;
        end = end->next;
        end->prev = temp;
        end->next = nullptr;
    }

    void print() {
        DNode<T>* temp = start;
        while (temp != nullptr)
        {
            std::cout << temp->value << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
        
    }



    ~DoubleList() {
        DNode<T>* temp = start;
        DNode<T>* current;

        while (temp != nullptr)
        {
            current = temp;
            delete current;
            temp = temp->next;
        }

    }

    
    friend DoubleList<T> reverse(DoubleList<T>& list) {
        
        DNode<T>* temp = list.end;
        DoubleList<T> newList(temp->value);
        temp = temp->prev;
        
        while (temp != nullptr)
        {
            newList.insert(temp->value);
            temp = temp->prev;
        }

        return newList;
        
    }


};

#endif