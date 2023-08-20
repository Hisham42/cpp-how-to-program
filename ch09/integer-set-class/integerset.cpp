#include "integerset.h"

Integerset::Integerset(vector<int> aa)
{
    for (size_t i = 0; i < aa.size(); i++)
    {
        insertInt(aa[i]);
    }

}

Integerset::Integerset(int arr[])
{
    int i{0};
    while (arr[i] != 0)
    {
        insertInt(arr[i]);
        i++;
    }
    

}

Integerset::Integerset()
{
}

bool Integerset::contains(int a)
{
    bool inVector{false};
    for (size_t i = 0; i < setOfInts.size(); i++)
    {
        if (a == setOfInts[i])
        {
            inVector = true;
            break;
        }
    }
    if (inVector)
    {
        return true;
    }
    else
    {
        return false;
    }
    
    

}

Integerset::~Integerset()
{
}


void Integerset::insertInt(int a)
{
    bool inVector{false};

    for (size_t i = 0; i < setOfInts.size(); i++)
    {
        if (a == setOfInts[i])
        {
            inVector = true;
            break;
        }
        
    }
    
    if (a >=0 && a <= 100 && inVector == false)
    {
        setOfInts.push_back(a);
        
    }
    
}

void Integerset::printInts()
{
    if (this->setOfInts.size() > 0)
    {
        cout << "{";
        for (size_t i = 0; i < setOfInts.size(); i++)
        {
            if (i == setOfInts.size() - 1)
            {
                cout << setOfInts[i];
            }
            else
            {
                cout << setOfInts[i] << ", ";
            }        
        }
        cout << "}" << endl;
    }
    else
    {
        cout << "Empty set." << endl;
    }
    
    
    
}

Integerset Integerset::unionThis(Integerset b)
{
    Integerset U;

    for (size_t i = 0; i < setOfInts.size(); i++)
    {
        U.insertInt(setOfInts[i]);
    }

    for (size_t i = 0; i < b.setOfInts.size(); i++)
    {
        U.insertInt(b.setOfInts[i]);
    }

    

    return U;

}

Integerset Integerset::IntersectThis(Integerset b)
{
    Integerset U = this->unionThis(b);

    Integerset n;


    for (size_t i = 0; i < U.setOfInts.size(); i++)
    {
        if (this->contains(U.setOfInts[i]) && b.contains(U.setOfInts[i]))
        {
            n.insertInt(U.setOfInts[i]);
        }
         
    }
    
    
    return n;
}

bool Integerset::isEqualTo(Integerset b)
{
    if (setOfInts == b.setOfInts)
    {
        cout << "True" << endl;
        return true;
    }
    else
    {
        cout << "False" << endl;
        return false;
    }
    
}