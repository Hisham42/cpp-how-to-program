#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <cctype>
#include "StackNode.h"

template<typename T>
class Stack : private StackNode<T>
{
private:
    StackNode<T>* base;
    StackNode<T>* right{nullptr};
public:

    Stack() {
        base = new StackNode<T>(T());
        right = base;
        base->right = nullptr;
        
    }

    Stack(Stack<T>& oldStack) {
        
        base = new StackNode<T>(oldStack.base->value);
        right = base;
        base->right = nullptr;

        StackNode<T>* temp = oldStack.base->right;

        while (temp != nullptr)
        {
            push(temp->value);
            temp = temp->right;
        }

    }

    Stack(T data) {
        base = new StackNode<T>(data);
        right = base;
        base->right = nullptr;


    }

    Stack(std::string string) {
        
        base = new StackNode<char>(*(string.cbegin()));
        right = base;
        base->right = nullptr;

        for (auto i = string.cbegin() + 1; i != string.cend(); i++)
        {
            if (*i != ' ')
            {
                push(*i);
            }
            
        }
        

    }

    void push(T data) {
        if (isempty())
        {
            base->value = data;
        }
        else
        {
            StackNode<T>* temp = right;
            temp->right = new StackNode<T>(data);
            right = temp->right;
        }
    }

    

    void pop() {
        if (isempty())
        {
            std::cerr << "Cannot Pop as Stack is empty" << std::endl; 
        }
        else if (base == right && base->value != T())
        {
            base->value = T();
        }
        else {
            StackNode<T>* temp = base;
            StackNode<T>* prev;
            while (temp->right->right != nullptr)
            {
                temp = temp->right;
            }

            delete right;
            right = nullptr;
            right = temp;
            right->right = nullptr;
        
        }

    }

    T stackRight() {

        if (isempty())
        {
            std::cerr << "Stack is empty, please add values first" << std::endl;
        }
        
        return right->value;

    }

    bool isempty() {

        if (base == right && base->value == T())
        {
            return true;
        }
        else
            return false;
        

    }

    void print() {

        if (isempty())
        {
            std::cout << "Stack is empty" << std::endl;
        }
        else {
            StackNode<T>* temp = base;
            while (temp != nullptr)
            {
                std::cout << temp->value;
                if (temp->right != nullptr)
                {
                    std::cout << " -> ";
                }
                
                temp = temp->right;
            }
            std::cout << std::endl;
        }
    }
    
    ~Stack() {
        StackNode<T>* temp = base;
        StackNode<T>* current;

        while (temp != nullptr) {
            current = temp;
            temp = temp->right;
            delete current;
        }
    }

    void operator=(Stack S2) {

        while (!isempty())
        {
            pop();
        }

        StackNode<T>* temp = S2.base;

        while (temp != nullptr)
        {
            push(temp->value);
            temp = temp->right;
        }
        
    }

    Stack<char> convertToPostfix() {
        Stack postfix('(');
        push(')');

        StackNode<char>* temp = base;
        while (!isempty())
        {
            if (isdigit(temp->value))
            {
                push(temp->value);
            }
            else if (temp->value == '(')
            {
                push(temp->value);
            }
            else if (temp->isOperator())
            {
                
            }
            else if (temp->value == ')')
            {
                
            }


            temp = temp->right;
        }

        return postfix;
    }



};


#endif 