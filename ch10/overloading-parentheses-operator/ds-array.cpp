#include "ds-array.h"

#include <stdexcept>


using namespace std;

// constructor 1
DsArray::DsArray(int r, int c)
    :rows{
        (r > 0 ? r : 
        throw invalid_argument{"Array rows must be greater than 0"})
    },
    columns{
        (c >= 0 ? c :
        throw invalid_argument{"Array columns must be greater than 0"})
    },

    ptr{new int*[rows]{}}
    {
        for (int i = 0; i < rows; ++i)
        {
            ptr[i] = new int[columns];
        }
        
    }

DsArray::DsArray(int c)
    :rows(1),
    columns{
        (c >= 0 ? c :
        throw invalid_argument{"Array columns must be greater than 0"})
    },

    ptr{new int*[rows]{}}
    {
        for (int i = 0; i < rows; ++i)
        {
            ptr[i] = new int[columns];
        }
        
    }

void DsArray::operator()(initializer_list<int> list)
{
    const int* pt = list.begin();

    for (int i = 0; i < rows; ++i)
    {
        {
            for (int j = 0; j < columns; ++j)
            {
                ptr[i][j] = *pt;
                pt++;

            }
        }
    }
}



// destructor
DsArray::~DsArray()
{
    for (int i = 0; i < rows; i++)
        {
            delete[] ptr[i];
        }
    delete[] ptr;
}

// >> cin

std::istream& operator>>(std::istream& input, DsArray& a)
{
    for (int i = 0; i < a.rows; ++i)
    {

        {
            for (int j = 0; j < a.columns; ++j)
            {
                std::cout << "Enter Array[" << i<< "][" << j << "]:" << std::endl;
                input >> a.ptr[i][j];
            }
        }
    }

    return input;
    
}

std::ostream& operator<<(std::ostream& output, const DsArray& a)
{
    output << "Array output:" << endl;

    for (int i = 0; i < a.rows; ++i)
    {
        for (int j = 0; j < a.columns; ++j)
        {
            output << a.ptr[i][j] << " ";
        }
        output << endl;
        
    }

    return output;
    
}

int& DsArray::operator()(int r, int c) const
{
    if (r >= rows || c >= columns)
    {
        throw invalid_argument{"Invalid Array index"};
    }
    
    return ptr[r][c];
}

DoubleSubscript DsArray::operator[](int r) 
{

    if (rows == 1)
    {
        DoubleSubscript secondSub(ptr[0], r);

        return secondSub;
    }

    DoubleSubscript secondSub(ptr[r], columns);

    return secondSub;
}



bool DsArray::operator==(DsArray& a) const
{
    if (rows == a.rows && columns == a.columns)
    {
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < columns; ++j)
            {
                if (ptr[i][j] != a.ptr[i][j])
                {
                    return false;
                }
            }  
        }
        return true;
    }
    else
    {
        return false;
    }
    
}

bool DsArray::operator!=(DsArray& a) const
{
    if (*this == a)
    {
        return false;
    }
    else
    {
        return true;
    }
    
}