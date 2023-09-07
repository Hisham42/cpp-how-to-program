#include "hourly-worker.h"
#include <string.h>
#include <iomanip>
#include <sstream>
using namespace std;

HourlyWorker::HourlyWorker(const string& first, const string& last,
   const string& ssn, int m, int d, int y, double w, double h)
: Employee(first, last, ssn, m, d, y)
{
    setWage(w);
    setHours(h);
    
}

HourlyWorker::~HourlyWorker()
{
}


// calculate earnings; override pure virtual function earnings in Employee
double HourlyWorker::earnings() const {
    double overtime{0};
    if (getHours() > 40)
    {
        overtime = getHours() - 40;
    }
    
   return getWage() * getHours() + overtime * 1.5 * getWage();
}

// return a string representation of CommissionEmployee's information 
string HourlyWorker::toString() const {
   ostringstream output;
   output << fixed << setprecision(2);
   output << "Piec Worker employee: " << Employee::toString()
      << "\nWage: " << getWage()
      << "\nNumber of Hours: " << getHours();
   return output.str();
}

void HourlyWorker::setWage(double w) {

    wage = w;
}
void HourlyWorker::setHours(double p) {
    hours = p;
}

double HourlyWorker::getWage() const {

   return wage;
}
double HourlyWorker::getHours() const {
   return hours;
}