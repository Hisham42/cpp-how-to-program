#ifndef PIECEWOKER_H
#define PIECEWOKER_H
#include "Employee.h"

class PieceWorker : public Employee
{
private:
    /* data */

    double wage;
    double pieces;

public:
    PieceWorker(const std::string&, const std::string&,
     const std::string &, int=1, int=1, int=1900, double=1, double=1);
    ~PieceWorker();

    virtual double earnings() const override; // calculate earnings        
    virtual std::string toString() const override; // string representation

    void setWage(double);
    void setPieces(double);

    double getWage() const;
    double getPieces() const;
};







#endif