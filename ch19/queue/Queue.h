#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <cctype>
#include "Customer.h"

template<typename T>
class Queue : private Customer<T>
{
private:
    Customer<T>* head;
    Customer<T>* tail{nullptr};
public:

    Queue() {
        head = new Customer<T>(T(), T(), T());
        tail = head;
        head->next = nullptr;
        
    }

    

    

    
    void enqueue(T number, T serviceTime, T arrivalTime) {
        if (isempty())
        {
            head->customerNumber = number;
            head->customerServiceTime = serviceTime;
            head->customerArrivalTime = arrivalTime;
        }
        else
        {
            Customer<T>* temp = new Customer<T>(number, serviceTime, arrivalTime);
            temp->next = tail;
            tail = temp;
        }
    }

    

    void dequeue() {
        if (isempty())
        {
           
        }
        else if (head == tail && head->customerNumber != T() && head->customerServiceTime !=T() && head->customerArrivalTime != T())
        {
            head->customerNumber = T();
            head->customerServiceTime = T();
            head->customerArrivalTime = T();
        }
        else {
            Customer<T>* temp = tail;
            Customer<T>* prev;
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

    T queueHeadNumber() {

        if (isempty())
        {
            
        }
        
        return head->customerNumber;

    }

    T queueHeadServiceTime() {

        
        
        return head->customerServiceTime;

    }

    T queueHeadCustomerNumber() {

        
        
        return head->customerNumber;

    }

    T queueHeadArrivalTime() {

        
        
        return head->customerArrivalTime;

    }

    bool isempty() {

        if (head == tail && head->customerNumber == T() && head->customerServiceTime == T() && head->customerArrivalTime == T())
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
            Customer<T>* temp = tail;
            while (temp != nullptr)
            {
                std::cout << temp->customerNumber;
                if (temp->next != nullptr)
                {
                    std::cout << " -> ";
                }
                
                temp = temp->next;
            }
            std::cout << std::endl;
        }
    }

    int currentCustomersCount() {
        int value{0};
        if (tail == nullptr)
        {
            return value;
        }
        else {
            Customer<T>* temp = tail;
            

            while (temp != nullptr) {
                value++;
                temp = temp->next;
               
            }
            return value;
        }
        
    }

    int maxWaitTime() {
        int value{0};
        if (tail == nullptr)
        {
            return value;
        }
        else {
            Customer<T>* temp = tail;
            

            while (temp != nullptr) {
                value += temp->customerServiceTime;
                temp = temp->next;
               
            }
            return value;
        }
        
    }
    
    ~Queue() {
        Customer<T>* temp = tail;
        Customer<T>* current;

        while (temp != nullptr) {
            current = temp;
            temp = temp->next;
            delete current;
        }
    }

    

};


#endif 