#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <memory>

template<typename T, size_t N>
class Array {
private:
    size_t arraySize;  
    std::unique_ptr<T[]> ptr;

public:
    Array<T, N>()
        :arraySize((N > 0) ? N : throw std::invalid_argument("Invalid Size")),
        ptr(std::make_unique<T[]>(arraySize))
    {

    }

    ~Array<T, N>() {

    }

    T& operator[](size_t index) {
        return (index < N) ? ptr[index] : throw std::range_error ("Invalid Index");
    }

    
    
};

#endif
