#include "name.h"
#include <string>
#include <stdexcept>
#include <sstream>
#include <iostream>


Name::Name(std::string first, std::string second, std::string third)
{
    try
    {
        setFirst(first);
        setMiddle(second);
        setLast(third);
    }
    catch(int code)
    {
        std::cout << "Invalid Name: " << code << std::endl;
    }
    
    
    

}

Name::~Name()
{
}

std::string Name::toString()
{

    std::string nam = LastName + " " + firstName + " " + middleName;

    return nam;
}

void Name::setFirst(std::string fir)
{
    if (fir =="")
    {
        throw 101;
    }
    else
    {
    firstName = fir;
    }
}

void Name::setMiddle(std::string sec)
{
    middleName = sec;
}

void Name::setLast(std::string thir)
{
    LastName = thir;
}



std::string Name::getFirst()
{
    return firstName;
}

std::string Name::getMiddle()
{
    return middleName;
}

std::string Name::getLast()
{
    return LastName;
}

