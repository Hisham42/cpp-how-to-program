#include <iostream>



template<typename T>
class HArray
{
private:
    size_t size;
    T* arr;
    size_t actualSize;
public:
    
    HArray(size_t siz) {
        arr = new T[siz];
        size = siz;
        actualSize = 0;

    }

    void insert(T data) {
        bool duplicateValue{false};
        if (actualSize < size)
        {
            for (size_t i = 0; i < actualSize; i++)
            {
                if (arr[i] == data)
                {
                    std::cout << "Duplicate Value" << std::endl;
                    duplicateValue = true;
                }
                
            }
            if (!duplicateValue)
            {
                arr[actualSize] = data;
                actualSize++;
            }
            
        }
        else
            std::cout << "Array is full." << std::endl;
        
    }

    void print() {
        for (size_t i = 0; i < size; i++)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
        
    }

    ~HArray() {
        delete[] arr;
    }

};




int main() {


    HArray<int> a1(20);

    a1.insert(10);
    a1.insert(7);
    a1.insert(17);
    a1.insert(20);
    a1.insert(12);
    a1.insert(11);
    a1.insert(13);
    a1.insert(14);
    a1.insert(10);
    a1.print();

    

}