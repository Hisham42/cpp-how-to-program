#include "poly.h"


Poly::Poly(initializer_list<Term> list)
{
    
    arraySize = list.size();

    const Term* pt = list.begin();

    ptr = new Term*[arraySize];

    for (int i = 0; i < arraySize; i++)
    {
        ptr[i] = new Term(*pt);
        pt++;
    }

    
}

Poly::Poly(int size)
: arraySize(size)
{
   
    ptr = new Term*[arraySize];

    for (int i = 0; i < size; i++)
    {
        ptr[i] = new Term();
        ptr[i]->setC(0);
        ptr[i]->setE(0);
        
    }

    

}


Poly::~Poly()
{
   
  
    delete[] ptr;

   
}

Poly Poly::operator+(const Poly& p) const
{
    int l{0};
    int k{this->expectedSize(p)};
    Poly returnP(k);

    bool match{false};
    
    for (size_t i = 0; i < arraySize || l < k; i++)
    {     
        match = false;

        for (size_t j = 0; j < p.arraySize || l < k; j++)
        {
            
            if (ptr[i]->getE() == p.ptr[j]->getE())
            {
                returnP.ptr[l]->setE(ptr[i]->getE());
                returnP.ptr[l]->setC(ptr[i]->getC() + p.ptr[j]->getC());
                l++;
                match = true;
                
            }

            if (j == p.arraySize - 1)
            {
                break;
            }
        }

        if (!match)
        {
            returnP.ptr[l]->setE(ptr[i]->getE());
            returnP.ptr[l]->setC(ptr[i]->getC());
            l++;
        }
        
        if (i == arraySize - 1)
        {
            break;
        }
    }

    for (int i = 0; l < k; i++)
    {
        if (p.ptr[i]->isIn(returnP))
        {
            returnP.ptr[l]->setE(p.ptr[i]->getE());
            returnP.ptr[l]->setC(p.ptr[i]->getC());
            l++;
        }
        if (l == k || i == p.arraySize - 1)
        {
            break;
        }
        
    }
  
    return returnP;
}



int Poly::getSize() const
{
    return arraySize;
}

Term Poly::getPtr(int& a) const
{
    return ptr[a];
}

int Poly::expectedSize(const Poly& p) const
{
    // reset status once applied
    for (int i = 0; i < arraySize; i++)
    {
        ptr[i]->setStatus(false);
    }

    for (int i = 0; i < p.arraySize; i++)
    {
        p.ptr[i]->setStatus(false);
    }
    
    
    int intersectionCounter{0};
    for (size_t i = 0; i < arraySize; i++)
    {
        for (size_t j = 0; j < p.arraySize; j++)
        {
            if (ptr[i]->getE() == p.ptr[j]->getE() && p.ptr[j]->getStatus() == false)
            {
                p.ptr[j]->setStatus(true);
                intersectionCounter++;
            }
        }
    }

    return this->arraySize + p.arraySize - intersectionCounter;
}

void Poly::operator=(const Poly& p) 
{
    arraySize = p.arraySize;
    
    for (size_t i = 0; i < arraySize; i++)
    {
        ptr[i] = new Term{p.ptr[i]};
    }
    
}


ostream& operator<<(ostream& output, const Poly& a)
{
    int bigEx{0}; // integer to determine the biggest Exponenet and start printing
    int counter{0}; // counter to go out of the loop once we print all terms

    if (a.isZero())
    {
        output << "Poly is Empty.";
        return output;
    }
    

    // for loop to detemine the big exponenet
    for (int i = 0; i < a.arraySize; i++)
    {
        if (bigEx < a.ptr[i]->getE())
        {
            bigEx = a.ptr[i]->getE();
        }  
    }

    // for loop to print the poly in order
    for (int j = 0; j < a.arraySize && counter < a.arraySize; j++)
    {
        if (a.ptr[j]->getE() == bigEx && a.ptr[j]->getStatus() == false)
        {
            bigEx--;

            if (a.ptr[j]->getE() == 0)
            {
                output << a.ptr[j]->getC();
            }
            else if (a.ptr[j]->getC() == 0)
            {
                /* do nothing */
            }
            else if (a.ptr[j]->getC() == 1)
            {
                output  << "X^" << a.ptr[j]->getE() << " + ";
            }
            else
            {
                output << a.ptr[j]->getC() << "X^" << a.ptr[j]->getE() << " + ";
            }
            
            a.ptr[j]->setStatus(true);

            j = -1;
            counter++;
        }
        if (j == a.arraySize -1)
        {
            bigEx--;
            j = -1;
        }
        
    }

    output << " = 0";

    return output;
}

Poly Poly::operator-(const Poly& p) const
{
    int l{0};
    int k{this->expectedSize(p)};
    Poly returnP(k); // create a temp poly

    bool match{false};
    
    for (size_t i = 0; i < arraySize || l < k; i++)
    {     
        match = false;

        for (size_t j = 0; j < p.arraySize || l < k; j++)
        {
            
            if (ptr[i]->getE() == p.ptr[j]->getE())
            {
                returnP.ptr[l]->setE(ptr[i]->getE());
                returnP.ptr[l]->setC(ptr[i]->getC() - p.ptr[j]->getC());
                l++;
                match = true;
                
            }

            if (j == p.arraySize - 1)
            {
                break;
            }
        }

        if (!match)
        {
            returnP.ptr[l]->setE(ptr[i]->getE());
            returnP.ptr[l]->setC(ptr[i]->getC());
            l++;
        }
        
        if (i == arraySize - 1)
        {
            break;
        }
    }

    for (int i = 0; l < k; i++)
    {
        if (p.ptr[i]->isIn(returnP))
        {
            returnP.ptr[l]->setE(p.ptr[i]->getE());
            returnP.ptr[l]->setC(0 - p.ptr[i]->getC());
            l++;
        }
        if (l == k || i == p.arraySize - 1)
        {
            break;
        }
        
    }
  
    return returnP;
}

Poly Poly::operator*(const Poly& p) const
{
    // detect return poly array size
    int rpArraySize = arraySize * p.arraySize;

    // instantiate a temp poly
    Poly returnP(rpArraySize);

    // create a k integer to iterate through the temp poly
    int k{0};

    // start multiplication assuming that the two polynominals are with the same X
    for (int i = 0; i < arraySize; i++)
    {
        for (int j = 0; j < p.arraySize; j++)
        {
            returnP.ptr[k]->setC(ptr[i]->getC() * p.ptr[j]->getC());
            returnP.ptr[k]->setE(ptr[i]->getE() + p.ptr[j]->getE());
            k++;

            if (j == p.arraySize - 1)
            {
                break;
            }

        }

        if (k == rpArraySize || i == p.arraySize - 1)
        {
            break;
        }
    }

    // now we have a temp not organized that needs to be reformulated


    return reformulatePoly(returnP);;
}


Poly reformulatePoly(const Poly& a)
{
    // reset status 
    

    int bigEx{0}; // integer to determine the biggest Exponenet

    // for loop to detemine the big exponenet
    for (int i = 0; i < a.arraySize; i++)
    {
        if (bigEx < a.ptr[i]->getE())
        {
            bigEx = a.ptr[i]->getE();
        }  
    }

    

    // calculate size
    int size{0};


    for (int j = bigEx; j >= 0; j--)
    {
        for (int i = 0; i < a.arraySize; i++)
        {
            if (a.ptr[i]->getE() == j)
            {
                size++;
                break;
            }
            
        }
    }

    // create the new reformulated poly

    Poly temp(size);
    int k{0}; // to iterate through temp
    int coeff{0}; // to set Coeff properly
    bool found{false}; // to increase k properly
    
    for (int j = bigEx; j >= 0; j--)
    {
        coeff = 0;
        
        for (int i = 0; i < a.arraySize; i++)
        {
            if (a.ptr[i]->getE() == j)
            {
                coeff += a.ptr[i]->getC();
                temp.ptr[k]->setC(coeff);

                temp.ptr[k]->setE(j);
                found = true;
            } 
        }

        if (found)
        {
            k++;
            found = false;
        }
        
        
    }

    return temp;
}


void Poly::operator*=(const Poly& p)
{
    if (this->isZero())
    {
        /* do nothing*/
    }
    else if (p.isZero())
    {
        *this = p;
    }
    else {
        *this = *this * p; 
    }
    
}

bool Poly::isZero() const{

    for (int i = 0; i < arraySize; i++)
    {
        if (ptr[i]->getC() != 0 || ptr[i]->getE() != 0)
        {
            return false;
        }
        
    }

    return true;
}



void Poly::operator+=(const Poly& p)
{
    *this = *this + p; 
    
}

void Poly::operator-=(const Poly& p)
{
    *this = *this - p; 
    
}