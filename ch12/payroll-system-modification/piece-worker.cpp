#include "piece-worker.h"
#include <iomanip>
#include <sstream>
using namespace std;



PieceWorker::PieceWorker(const string& first, const string& last,
   const string& ssn, int m, int d, int y, double w, double p)
: Employee(first, last, ssn, m, d, y)
{
    wage = w;
    pieces = p;
}

PieceWorker::~PieceWorker()
{
}


// calculate earnings; override pure virtual function earnings in Employee
double PieceWorker::earnings() const {
   return getWage() * getPieces();
}

// return a string representation of CommissionEmployee's information 
string PieceWorker::toString() const {
   ostringstream output;
   output << fixed << setprecision(2);
   output << "Piec Worker employee: " << Employee::toString()
      << "\nWage: " << getWage()
      << "\nNumber of pieces: " << getPieces();
   return output.str();
}

void PieceWorker::setWage(double w) {

    wage = w;
}
void PieceWorker::setPieces(double p) {
    pieces = p;
}

double PieceWorker::getWage() const {

   return wage;
}
double PieceWorker::getPieces() const {
   return pieces;
}