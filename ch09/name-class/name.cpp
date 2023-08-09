#include "name.h"
#include <string>


Name::Name(std::string first, std::string second, std::string third, std::string salut)
{

    setFirst(first);
    setMiddle(second);
    setLast(third);
    setSalut(salut);

}

Name::~Name()
{
}

std::string Name::toString()
{

    std::string nam = salutation + " " + LastName + " " + firstName + " " + middleName;

    return nam;
}

void Name::setFirst(std::string fir)
{
    firstName = fir;
}

void Name::setMiddle(std::string sec)
{
    middleName = sec;
}

void Name::setLast(std::string thir)
{
    LastName = thir;
}

void Name::setSalut(std::string sal)
{
    salutation = sal;
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

std::string Name::getSalut()
{
    return salutation;
}