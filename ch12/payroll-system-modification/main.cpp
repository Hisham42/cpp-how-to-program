// Fig. 12.17: fig12_17.cpp
// Processing Employee derived-class objects with static binding 
// then polymorphically using dynamic binding.
#include <iostream>
#include <iomanip>
#include <vector>
#include "Employee.h"
#include "SalariedEmployee.h" 
#include "CommissionEmployee.h"  
#include "BasePlusCommissionEmployee.h" 
#include "piece-worker.h"
#include "hourly-worker.h"
#include "Date.h"
#include <ctime>

using namespace std;

void virtualViaPointer(const Employee* const); // prototype
void virtualViaReference(const Employee&); // prototype
int getCurrentMonth();

int main() {
   cout << fixed << setprecision(2); // set floating-point formatting

   // create derived-class objects                        
   SalariedEmployee salariedEmployee{
      "John", "Smith", "111-11-1111", 800, 10, 6, 1994};
   CommissionEmployee commissionEmployee{
      "Sue", "Jones", "333-33-3333", 10000, .06, 9, 22, 2002};
   BasePlusCommissionEmployee basePlusCommissionEmployee{
      "Bob", "Lewis", "444-44-4444", 5000, .04, 300, 3, 16, 1994};

   PieceWorker pieceWorkerEmployee{
      "Ahmed", "Ghaish", "555-55-5555", 2, 10, 1990, 12, 50
   };

   HourlyWorker hourlyWorkerEmployee{
      "Hisham", "Ghaish", "666-66-6666", 2, 10, 1987, 20, 50
   };

   

   
   // create and initialize vector of three base-class pointers        
   vector<Employee *> employees{&salariedEmployee, &commissionEmployee,
      &basePlusCommissionEmployee, &pieceWorkerEmployee,
       &hourlyWorkerEmployee};
   
   for (const Employee* employeePtr : employees) {
      
      
      virtualViaPointer(employeePtr);
   }


}

// call Employee virtual functions toString and earnings off a   
// base-class pointer using dynamic binding                   
void virtualViaPointer(const Employee* const baseClassPtr) {

   if (baseClassPtr->getBirthMonth() == getCurrentMonth())
   {
      cout << baseClassPtr->toString()
      << "\nearned $" << baseClassPtr->earnings() + 100 << "\n\n";
   }
   else
   {
      cout << baseClassPtr->toString()
      << "\nearned $" << baseClassPtr->earnings() << "\n\n";
   }

   
}


// get current month

int getCurrentMonth() {
   time_t currentTime = time(nullptr);
   tm* timeInfo = localtime(&currentTime);

   int currentMonth = timeInfo->tm_mon;

   return currentMonth + 1;
}

