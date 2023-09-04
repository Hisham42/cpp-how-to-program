#include "twodaypackage.h"



TwoDayPackage::TwoDayPackage(string rn, string ra, string rc, string rs, string rz,
    double pw, double pc,
    string sn, string sa, string sc, string ss, string sz,
    double ff
    )
    : Package(rn, ra, rc, rs, rz, pw, pc, sn, sa, sc, ss, sz)
{
    setFlatFee(ff);
}

TwoDayPackage::~TwoDayPackage()
{
}

void TwoDayPackage::setFlatFee(double a) {
    if (a < 0)
    {
        throw invalid_argument("Invalid Flat Fee.");
    }
    flatFee = a;
}

double TwoDayPackage::calculateCost() const {
    return flatFee + Package::calculateCost();
}

