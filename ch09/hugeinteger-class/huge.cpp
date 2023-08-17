#include "huge.h"
#include <string>
#include <iostream>

bool isZero(int *arr, int size);



Huge::Huge(std::string integ)
: stringStorage(integ)
{
    for (size_t i = 0; i < 40; i++)
    {
        numberStorage[i] = 0;
    }
    
    input(integ); //12345679

   
    
    


}

Huge::~Huge()
{
}

void Huge::input(std::string integ)
{
    
    int stringLength = integ.length();

    int j = stringLength - 1;
    int k{0};

    for (size_t i = 39; i >= 0; i--)
    {
        if (stringStorage[k] == char(45))
        {
            i++;
            this->Negative = true;
                 
        }
        else
        {
            this->numberStorage[i] = (integ[j]) -  48;
            j--;
        }

        k++;
        
        if (stringStorage[0] == char(45))
        {
            if (j == 0)
            {
                break;
            }
        }
        
        else if (j == -1)
        {
            break;
        }
        
    }
    
}

void Huge::output()
{
    int count{0};
    bool startPrinting{false};
    bool negPrinted{false};

    
    
    for (size_t i = 0; i < 40; i++)
    {
        
        if(this->numberStorage[i] != 0)
        {
            startPrinting = true;
        }
        if (startPrinting)
        {
            if (this->Negative && !negPrinted)
            {
                std::cout << "-";
                negPrinted = true;
            }
            std::cout << this->numberStorage[i];
            count++;
        }   
    }
    if (count == 0)
    {
        std::cout << "0";
    }
    
    std::cout << std::endl;    
}

void Huge::add(Huge bigInt2)
{
    
    int rest{0};
    int addition{0};

    if (stringStorage[0] == char(45) && bigInt2.stringStorage[0] != char(45))
    {

        Huge bigInt3(this->stringStorage);
        
        bigInt3.stringStorage[0] = char(48);

        if (this->isGreaterThan(bigInt2))
        {
            bigInt3.Negative = true;
            bigInt3.subtract(bigInt2);
        }
        else
        {
            
            bigInt2.subtract(bigInt3);
        }
        

        
    }
    else if (stringStorage[0] != char(45) && bigInt2.stringStorage[0] == char(45))
    {

        bigInt2.stringStorage[0] = char(48);
        Huge bigInt3(bigInt2.stringStorage);
        

        this->subtract(bigInt3);
    }

    else if(stringStorage[0] == char(45) && bigInt2.stringStorage[0] == char(45))
    {
        
        Huge bigInt3(this->stringStorage);

        bigInt2.stringStorage[0] = char(48);
        Huge bigInt4(bigInt2.stringStorage);

        bigInt4.Negative = true;
        bigInt3.Negative = true;

        
        
        bigInt4.add(bigInt3);

    }
    
    

    else
    {
        Huge bigIntOperator(this->stringStorage);
        bigIntOperator.Negative = this->Negative;

        for (int i = 39; i >= 0; i--)
        {
            if (isZero(numberStorage, i)&& isZero(bigInt2.numberStorage ,i)&& rest == 0)
            {
                break;
            }
            else
            {
                addition = numberStorage[i] + bigInt2.numberStorage[i] + rest;
                if (addition > 9)
                {
                    bigIntOperator.numberStorage[i] = addition % 10;
                    rest = 1;    
                }
                else
                {
                    bigIntOperator.numberStorage[i] = addition;
                    rest = 0;
                }
            }
            
            
        }

        bigIntOperator.output();
    }
    
    
}

void Huge::subtract(Huge bigInt2)
{
    if (stringStorage[0] == char(45) && bigInt2.stringStorage[0] != char(45))
    {

        Huge bigInt3(this->stringStorage);
        bigInt3.Negative = true;
        bigInt3.stringStorage[0] = char(48);

        bigInt3.add(bigInt2);
    }

    else if (bigInt2.stringStorage[0] == char(45) && stringStorage[0] != char(45))
    {

        bigInt2.stringStorage[0] = char(48);
        Huge bigInt3(bigInt2.stringStorage);

        this->add(bigInt3);
    }

    else if(stringStorage[0] == char(45) && bigInt2.stringStorage[0] == char(45))
    {
        
        Huge bigInt3(this->stringStorage);

        if (bigInt3.isGreaterThan(bigInt2))
        {
            bigInt3.Negative = true;
        }
        


        bigInt3.add(bigInt2);

    }
    

    else
    {
       
        Huge bigIntOperator(this->stringStorage);
        bigIntOperator.Negative = this->Negative;
    
        //who is the bigger
        int subtraction{0};
        int rest{0};
        bool isNegative{false};

        if (stringStorage.length() == bigInt2.stringStorage.length())
        {
            for (size_t i = 40 - stringStorage.length(); i < 40; i++)
            {
                if (numberStorage[40 - stringStorage.length()] < bigInt2.numberStorage[40 - stringStorage.length()])
                {
                    isNegative = true;
                }
            }
            
        }
        else if (bigInt2.stringStorage.length() > stringStorage.length())
        {
            isNegative = true;
        }
        

        if (stringStorage.length() < bigInt2.stringStorage.length() || isNegative)
        {
            bigIntOperator.Negative = true;

            
            for (int i = 39; i >= 0; i--)
            {
                if (isZero(bigInt2.numberStorage, i) && isZero(bigInt2.numberStorage, i) && rest == 0)
                {
                    break;
                }
                else
                {
                    subtraction = bigInt2.numberStorage[i] - numberStorage[i] - rest;
                    if (subtraction >= 0)
                    {
                        bigIntOperator.numberStorage[i] = subtraction;
                        rest = 0;
                    }
                    else
                    {
                        bigIntOperator.numberStorage[i] = 10 + subtraction;
                        rest = 1;
                    }
                }
                
            
            }

        }
        else
        {
            for (int i = 39; i >= 0; i--)
            {
                
                if (isZero(numberStorage, i) && isZero(bigInt2.numberStorage, i) && rest == 0)
                {
                    break;
                }
                else
                {
                    subtraction = numberStorage[i] - bigInt2.numberStorage[i] - rest;
                    if (subtraction >= 0)
                    {
                        bigIntOperator.numberStorage[i] = subtraction;
                        rest = 0;
                    }
                    else
                    {
                        bigIntOperator.numberStorage[i] = 10 + subtraction;
                        rest = 1;
                    }
                }
                
            
            }

        }

        bigIntOperator.output();
    }

}

bool isZero(int *arr, int cap)
{

    if (arr[cap] == 0 && cap == 0)
    {
        return true;
    }
    else
    {
        isZero(arr, cap - 1);
    }

    return false;
}

bool Huge::isEqualTo(Huge bigInt2)
{
   if (stringStorage.length() == bigInt2.stringStorage.length() && this->Negative == bigInt2.Negative)
    {
        for (size_t i = 0; i < 40; i++)
        {
            if (numberStorage[i] != bigInt2.numberStorage[i])
            {
                return false;
            }
            
        }
        return true;
        
    }
    else
    {
        return false;
    }
        
}

bool Huge::isNotEqualTo(Huge bigInt2)
{
    if (this->isEqualTo(bigInt2))
    {
        return false;
    }
    else
    {
        return true;
    }
    
}

bool Huge::isGreaterThan(Huge bigInt2)
{
    bool isGreater{false};

    if (this->Negative == true && bigInt2.Negative == false)
    {
        return false;
    }
    
    else if (this->Negative == false && bigInt2.Negative == true)
    {
        return true;
    }

    else if (this->Negative == true && bigInt2.Negative == true)
    {
        if (stringStorage.length() == bigInt2.stringStorage.length())
        {
            for (size_t i = 0; i < 40; i++)
            {
                if (numberStorage[i] < bigInt2.numberStorage[i])
                {
                    isGreater = true;
                }
            }
        }
        else if (stringStorage.length() < bigInt2.stringStorage.length())
        {
            isGreater = true;
        }
        
    }

    else if (this->Negative == false && bigInt2.Negative == false)
    {

        if (stringStorage.length() == bigInt2.stringStorage.length())
        {
            for (size_t i = 0; i < 40; i++)
            {
                if (numberStorage[i] > bigInt2.numberStorage[i])
                {
                    isGreater = true;
                }
            }
            
        }
    
        else if (stringStorage.length() > bigInt2.stringStorage.length())
        {
            isGreater = true;
        }
    }
    
    return isGreater;
    
}

bool Huge::isGreaterThanOrEqualTo(Huge bigInt2)
{
    if (this->isGreaterThan(bigInt2) || this->isEqualTo(bigInt2))
    {
        return true;
    }

    else
    {
        return false;
    }
    
}

bool Huge::isLessThanOrEqualTo(Huge bigInt2)
{
    if (!this->isGreaterThan(bigInt2) || this->isEqualTo(bigInt2))
    {
        return true;
    }

    else
    {
        return false;
    }
}

void Huge::setString(std::string intt)
{
    stringStorage = intt;
}
void Huge::setNumber(int* num)
{
    for (int i = 0; i < 40; i++)
    {
        numberStorage[i] = num[i];
    }
    
}
void Huge::setNegative(bool neg)
{
    Negative = neg;
}