#include "motor.h"
#include <string>


//constructor
Motor::Motor(
    std::string m, std::string f, 
    int y, std::string c, 
    int e
    )
    :make(m), fuelType(f), color(c),
    ptrYearOfManufacture{new int{y}},
    ptrEngineCapacity{new int{e}} {           }

Motor::~Motor()
{
    delete[] ptrYearOfManufacture;
    delete[] ptrEngineCapacity;
}


/*set&get for each data member*/

//setters

void Motor::setMake(std::string vmake) {
    make= vmake;

}

void Motor::setFuelType(std::string vFuelType) {
    fuelType = vFuelType;

}

void Motor::setYear(int vYear) {
    *ptrYearOfManufacture = vYear;

}

void Motor::setEngineCapacity(int vEngineCapacity) {
    *ptrEngineCapacity = vEngineCapacity;

}

void Motor::setColor(int vColor) {
    color = vColor;

}



//getters

std::string Motor::getMake() const {
    return make;

}

std::string Motor::getFuelType() const {
    return fuelType;

}

int& Motor::getYear() const {
    return *ptrYearOfManufacture;

}

int& Motor::getEngineCapacity() const {
    return *ptrEngineCapacity;

}

std::string Motor::getColor() const {
    return color;

}

//getInvoiceAmount

void Motor::displayCarDetails() {
    std::cout << "Make: " << getMake() << "\n";

    std::cout << "Fuel Type: " << getFuelType() << "\n";

    std::cout << "Year: " << getYear() << "\n";

    std::cout << "Engine Capacity: " << getEngineCapacity() << "\n";

    std::cout << "Color: " << getColor() << "\n";
}

bool Motor::operator==(Motor& a)
{
    if (
        make == a.make && fuelType == a.fuelType &&
        *ptrYearOfManufacture == *a.ptrYearOfManufacture &&
        color == a.color && *ptrEngineCapacity ==*a.ptrEngineCapacity
        )
    {
        return true;
    }

    else
    {
        return false;
    }
    
}

bool Motor::operator!=(Motor& a)
{
    return !operator==(a);
    
}

bool Motor::operator>(Motor& a)
{
    if (*ptrYearOfManufacture < *a.ptrYearOfManufacture)
    {
        return true;
    }
    else
    {
        return false;
    }
    
    
}

bool Motor::operator<(Motor& a)
{
    return !operator>(a);

}

std::ostream& operator<<(std::ostream& output, Motor& a)
{
    output << "Make: " << a.getMake() << "\n";

    output << "Fuel Type: " << a.getFuelType() << "\n";

    output << "Year: " << a.getYear() << "\n";

    output << "Engine Capacity: " << a.getEngineCapacity() << "\n";

    output << "Color: " << a.getColor() << "\n";

    return output;
}