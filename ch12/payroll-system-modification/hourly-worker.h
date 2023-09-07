#ifndef HOURLYWORKER_H
#define HOURLYWORKER_H
#include "Employee.h"

class HourlyWorker : public Employee
{
private:
    /* data */

    double wage;
    double hours;
public:
    HourlyWorker(const std::string&, const std::string&, const std::string &
    , int=1, int=1, int=1900, double=1, double=1);
    ~HourlyWorker();

    virtual double earnings() const override; // calculate earnings        
    virtual std::string toString() const override; // string representation

    void setWage(double);
    void setHours(double);

    double getWage() const;
    double getHours() const;
};







#endif