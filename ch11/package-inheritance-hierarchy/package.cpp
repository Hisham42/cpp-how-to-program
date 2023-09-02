#include "package.h"



Package::Package(
    string rn, string ra, string rc, string rs, string rz,
    double pw, double pc,
    string sn, string sa, string sc, string ss, string sz
    )
{
    setNameR(rn); // set receiver name
    setNameS(sn); // set sender name

    setAddressR(ra); // set receiver address
    setAddressS(sa); // set sender address

    setCityR(rc); // set receiver city
    setCityS(sc); // set sender city

    setStateR(rs); // set receiver state
    setStateS(ss); // set sender state

    setZipCodeR(rz); // set receiver Zip Code
    setZipCodeS(sz); // set sender Zip Code

    setWeight(pw); // set receiver weight

    setCostPerOunce(pc); // set receiver Cost Per Ounce
    

}

Package::~Package()
{
}

// set receiver name
void Package::setNameR(string a) {
    nameR = a;
}

// set sender name
void Package::setNameS(string a) {
    nameS = a;
}

// set receiver address
void Package::setAddressR(string a) {
    addressR = a;
}

// set sender address
void Package::setAddressS(string a) {
    addressS = a;
}

// set receiver city
void Package::setCityR(string a) {
    cityR = a;
}

// set sender city
void Package::setCityS(string a) {
    cityS = a;
}

// set receiver state
void Package::setStateR(string a) {
    stateR = a;
}

// set sender state
void Package::setStateS(string a) {
    stateS = a;
}

// set receiver zip code
void Package::setZipCodeR(string a) {
    zipCodeR = a;
}

// set sender zip code
void Package::setZipCodeS(string a) {
    zipCodeS = a;
}

// set package weight
void Package::setWeight(double a) {
    if (a <= 0)
    {
        throw invalid_argument("Invalid Package Weight.");
    }
    
    weight = a;
}

// set package Cost Per Ounce
void Package::setCostPerOunce(double a) {
    if (a <= 0)
    {
        throw invalid_argument("Invalid Package Cost/Ounce.");
    }
    costPerOunce = a;
}

// get receiver name
string Package::getNameR() const{
    return nameR;
}

// get sender name
string Package::getNameS() const{
    return nameS;
}

// get receiver address
string Package::getAddressR() const{
    return addressR;
}

// get sender address
string Package::getAddressS() const{
    return addressS;
}

// get receiver city
string Package::getCityR() const{
    return cityR;
}

// get sender city
string Package::getCityS() const{
    return cityS;
}

// get receiver state
string Package::getStateR() const{
    return stateR;
}

// get sender state
string Package::getStateS() const{
    return stateS;
}

// get receiver zip code
string Package::getZipCodeR() const{
    return zipCodeR;
}

// get sender zip code
string Package::getZipCodeS() const{
    return zipCodeS;
}

// get package weight
double Package::getWeight() const{
    return weight;
}

// get package Cost Per Ounce
double Package::getCostPerOunce() const{
    return costPerOunce;
}

// cost = weight * costPerOunce
double Package::calculateCost() const {
    return weight * costPerOunce;
}

void Package::displayPackage() const{
    cout 
        << "Package Informations: " 
        << "\nWeight: " << getWeight() 
        << "\nCost: " << calculateCost()

        << "\n\nReceiver Informations: "
        << "\nName: " << getNameR()
        << "\nAdress: " << getAddressR()
        << "\nCity: " << getCityR()
        << "\nState: " << getStateR()
        << "\nZipCode: " << getZipCodeR()

        << "\n\nSender Informations: "
        << "\nName: " << getNameS()
        << "\nAdress: " << getAddressS()
        << "\nCity: " << getCityS()
        << "\nState: " << getStateS()
        << "\nZipCode: " << getZipCodeS() << "\n" << endl;

}