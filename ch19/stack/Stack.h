#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "StackItem.h"

template<typename T>
class Stack : private StackItem<T>
{
private:
    StackItem<T>* base;
    StackItem<T>* top{nullptr};
public:

    Stack() {
        base = new StackItem<T>(T());
        top = base;
        base->up = nullptr;
        
    }

    Stack(T data) {
        base = new StackItem<T>(data);
        top = base;
        base->up = nullptr;


    }

    void push(T data) {

        StackItem<T>* temp = top;
        temp->up = new StackItem<T>(data);
        top = temp->up;
        
    }

    

    T pop() {

        StackItem<T>* temp = base;
        StackItem<T>* prev;
        T val = top->value;
        while (temp->up->up != nullptr)
        {
            temp = temp->up;
        }

        delete top;
        top = nullptr;
        top = temp;
        top->up = nullptr;
        
        return val;

    }

    void print() {
        StackItem<T>* temp = base;
        while (temp != nullptr)
        {
            std::cout << temp->value << " ";
            temp = temp->up;
        }
        std::cout << std::endl;
        
    }
    
    ~Stack() {
        StackItem<T>* temp = base;
        StackItem<T>* current;

        while (temp != nullptr) {
            current = temp;
            temp = temp->up;
            delete current;
        }
    }
};


#endif 