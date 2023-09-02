#ifndef PACKAGE_H
#define PACKAGE_H

#include <iostream>
#include <sstream>

using namespace std;

class Package
{



private:
    /* data */

    string nameR; // name of receipient
    string nameS; // name of sender

    string addressR; // address of receipient
    string addressS; // address of sender

    string cityR; // city of receipient
    string cityS; // city of sender


    string stateR; // state of receipient
    string stateS; // state of sender

    string zipCodeR; // zip code of receipient
    string zipCodeS; // zip code of sender

    double weight; // weight of the package in ounce
    double costPerOunce; // cost per ounce

public:
    Package(
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
        string="Sender Zip Code"
        );


    ~Package();

    virtual double calculateCost() const; // weight*costPerOunce
    void displayPackage() const; // print package info
    // setters

    void setNameR(string); // set receiver name
    void setNameS(string); // set sender name

    void setAddressR(string); // set receiver address
    void setAddressS(string); // set sender address

    void setCityR(string); // set receiver city
    void setCityS(string); // set sender city

    void setStateR(string); // set receiver state
    void setStateS(string); // set sender state

    void setZipCodeR(string); // set receiver Zip Code
    void setZipCodeS(string); // set sender Zip Code

    void setWeight(double); // set package weight
    void setCostPerOunce(double); // set package Cost Per Ounce
    

    // getters
    
    string getNameR() const; // get receiver name
    string getNameS() const; // get sender name

    string getAddressR() const; // get receiver address
    string getAddressS() const; // get sender address

    string getCityR() const; // get receiver city
    string getCityS() const; // get sender city

    string getStateR() const; // get receiver state
    string getStateS() const; // get sender state

    string getZipCodeR() const; // get receiver Zip Code
    string getZipCodeS() const; // get sender Zip Code

    double getWeight() const; // get package weight
    double getCostPerOunce() const; // get package Cost Per Ounce



};


#endif