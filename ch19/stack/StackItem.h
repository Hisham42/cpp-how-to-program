#ifndef STACKITEM_H
#define STACKITEM_H

template<typename T>
class StackItem
{
public:
    T value;
    StackItem<T>* up;

    StackItem(T data) : value(data), up(nullptr) {}
    StackItem() : value(T()), up(nullptr) {}
};



#endif 