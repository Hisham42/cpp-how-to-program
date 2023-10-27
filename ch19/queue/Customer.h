#ifndef CUSTOMER_H
#define CUSTOMER_H

template<typename T>
class Customer
{
public:
    T customerNumber;
    T customerServiceTime;
    T customerArrivalTime;
    Customer<T>* next;

    Customer(T number, T serviceTime, T arrivalTime) : customerNumber(number), customerServiceTime(serviceTime),
        customerArrivalTime(arrivalTime), next(nullptr) {}

    Customer() : customerNumber(T()), customerServiceTime(T()), customerArrivalTime(T()), next(nullptr) {}    
};



#endif