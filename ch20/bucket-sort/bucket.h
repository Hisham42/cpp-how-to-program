#ifndef BUCKET_H
#define BUCKET_H
#include <iostream>

class Bucket
{
private:
    int* arrayPtr{nullptr};
    int arraySize{-1};
public:
    Bucket(int size) : arrayPtr (new int[size]) {
        
        arraySize = size;
        for (int i = 0; i < arraySize; i++) {
            arrayPtr[i] = 0; // Initialize all elements to 0
        }
        
    }

    void insertValueAt(int value, int at) {
        if (at < arraySize)
        {
            arrayPtr[at] = value;
        }
        else
        {
            std::cerr << "Cannot insert at Index " << at << std::endl;
        }
    }

    void printArray() {
        for (size_t i = 0; i < arraySize; i++)
        {
            std::cout << arrayPtr[i] << " ";
        }
        std::cout << std::endl;
        
    }

    void bucketSort(int passLimit) {
        // 2d constructor
        int** twoDimension = new int*[arraySize];
        for (size_t i = 0; i < arraySize; i++)
        {
            twoDimension[i] = new int[arraySize];
        }

        for (size_t i = 0; i < arraySize; i++)
        {
            for (size_t j = 0; j < arraySize; j++)
            {
                twoDimension[i][j] = 0;
            }
            
        }

        int tenthPath{1};

        for (size_t i = 0; i < passLimit; i++)
        {
            tenthPath *= 10;
        }
        


        for (size_t pass = 1; pass < tenthPath; pass *= 10)
        {
            // distribution pass
            int y = 0;

            for (size_t i = 0; i < arraySize; i++)
            {
                if (arrayPtr[i] != 0)
                {   
                    while (twoDimension[bucketIndex(arrayPtr[i], pass)][y] != 0)
                    {
                        y++;
                    }

                    twoDimension[bucketIndex(arrayPtr[i], pass)][y] = arrayPtr[i];

                }   
            }

            // gathering pass
            int x{0};
            for (size_t i = 0; i < arraySize; i++)
            {
                for (size_t j = 0; j < arraySize; j++)
                {
                    if (twoDimension[i][j] != 0)
                    {
                        arrayPtr[x] = twoDimension[i][j];
                        // clear value
                        twoDimension[i][j] = 0;
                        x++;
                    }
                    
                }
                
            }


            
        }
        
      
        // 2d destructor
        for (size_t i = 0; i < arraySize; i++)
        {
            delete[] twoDimension[i];
        }
        delete[] twoDimension;
        
    }

    int bucketIndex(int num, int i) {
            return (num / i) % 10;
        }

    ~Bucket() {
        delete[] arrayPtr;
    }
};


#endif