#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H

#include "package.h"

class TwoDayPackage : public Package
{
private:
    /* data */
    double flatFee;
public:
    TwoDayPackage(
        // receipient
        string="Receipient Name", 
        string="Receipient Adress", 
        string="Receipient City", 
        string="Receipient State", 
        string="Receipient Zip Code", 

        //package
        
        double=1, 
        double=1, 

        // sender
        string="Sender Name", 
        string="Sender Adress", 
        string="Sender City", 
        string="Sender State", 
        string="Sender Zip Code",
        double=0
        );

    ~TwoDayPackage();

    void setFlatFee(double); // set flat fee

    double calculateCost() const override;
   
};







#endif