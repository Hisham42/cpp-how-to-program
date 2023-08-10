#include <string>
#include "name.h"
#include "date.h"

#ifndef STUDENT_H
#define STUDENT_H

class Student
{
private:
    Name name;
    Date date;
    std::string sex, email;
    double registrationNumber;


public:
    Student(Name name, std::string sex, Date date, double registrationNumber, std::string email);

    //setters
    
    void setSex(std::string sex);
    void setEmail(std::string email);
    void setRegistrationNumber(double registrationNumber);

    //getters
    
    std::string getSex();
    std::string getEmail();
    double getRegistrationNumber();
    void getStudentName();
    void getDate();

    ~Student();
};

#endif