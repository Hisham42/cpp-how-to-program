#include <iostream>
#include "student.h"



Student::Student(Name n, std::string sex, Date d, double registrationNumber, std::string email)

: name(n), date(d)

{
    setSex(sex);
    setEmail(email);
    setRegistrationNumber(registrationNumber);
}

Student::~Student()
{

}

//setters

void Student::setSex(std::string sex)
{
    this->sex = sex;
}
void Student::setEmail(std::string email)
{
    this->email = email;
}

void Student::setRegistrationNumber(double registrationNumber)
{
    this->registrationNumber = registrationNumber;
}


//getters

std::string Student::getSex()
{
    return sex;
}
std::string Student::getEmail()
{
    return email;
}

double Student::getRegistrationNumber()
{
    return registrationNumber;
}

void Student::getStudentName()
{
    std::cout << name.getFirst() << name.getMiddle() << name.getLast() << std::endl;
}

void Student::getDate()
{
    std::cout << date.toString() << std::endl;
}