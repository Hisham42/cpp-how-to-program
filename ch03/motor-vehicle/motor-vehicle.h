#include <string>
#include <iostream>

class MotorVehicle
{
private:
    /* part number (str) - part description (str) - quantity (int) - price (int) - VAT (double) - discount (double) */ 
    //constructors

    std::string make;
    std::string fuelType;
    int yearOfManufacture;
    std::string color;
    int engineCapacity;

public:
    //constructor
    MotorVehicle(std::string inMake, std::string inFuelType, int inYearOfManufacture,
    std::string inColor, int inEngineCapacity) 
    : make{inMake}, fuelType{inFuelType}, yearOfManufacture{inYearOfManufacture},
    color{inColor}, engineCapacity{inEngineCapacity} {

    }
    /*set&get for each data member*/

    //setters

    void setMake(std::string vmake) {
        make = vmake;

    }

    void setFuelType(std::string vFuelType) {
        fuelType = vFuelType;

    }

    void setYear(int vYear) {
        yearOfManufacture = vYear;

    }

    void setEngineCapacity(int vEngineCapacity) {
        engineCapacity = vEngineCapacity;

    }

    void setColor(int vColor) {
        color = vColor;

    }



    //getters

    std::string getMake() {
        return make;

    }

    std::string getFuelType() {
        return fuelType;

    }

    int getYear() {
        return yearOfManufacture;

    }

    int getEngineCapacity() {
        return engineCapacity;

    }

    std::string getColor() {
        return color;

    }

    //getInvoiceAmount

    void displayCarDetails() {
        std::cout << "Make: " << getMake() << "\n";

        std::cout << "Fuel Type: " << getFuelType() << "\n";

        std::cout << "Year: " << getYear() << "\n";

        std::cout << "Engine Capacity: " << getEngineCapacity() << "\n";

        std::cout << "Color: " << getColor() << "\n";
    }

    
};
