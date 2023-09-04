#include "overnightpackage.h"



OvernightPackage::OvernightPackage(string rn, string ra, string rc, string rs, string rz,
    double pw, double pc,
    string sn, string sa, string sc, string ss, string sz,
    double af
    )
    : Package(rn, ra, rc, rs, rz, pw, pc, sn, sa, sc, ss, sz)
{
    setAdditionFee(af);
}

OvernightPackage::~OvernightPackage()
{
}

void OvernightPackage::setAdditionFee(double a) {
    if (a < 0)
    {
        throw invalid_argument("Invalid Flat Fee.");
    }
    additionFee = a;
}

double OvernightPackage::calculateCost() const {
    return additionFee * Package::getWeight()  + Package::calculateCost();
}

