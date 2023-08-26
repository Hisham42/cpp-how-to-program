#include <string>
#include <iostream>
#include <sstream>


#ifndef MOTOR_H
#define MOTOR_H


class Motor
{

    friend std::ostream& operator<<(std::ostream&, Motor&);

private:
    /* part number (str) - part description (str) - quantity (int) - price (int) - VAT (double) - discount (double) */ 
    //constructors

    std::string make;
    std::string fuelType;
    int* ptrYearOfManufacture;
    std::string color;
    int* ptrEngineCapacity;

public:
    explicit Motor(std::string, std::string, int, std::string, int);

    ~Motor();

    void setMake(std::string);
    void setFuelType(std::string);
    void setYear(int);
    void setEngineCapacity(int);
    void setColor(int);

    std::string getMake() const;
    std::string getFuelType() const;
    int& getYear() const;
    int& getEngineCapacity() const;
    std::string getColor() const;

    void displayCarDetails();

    bool operator==(Motor&);
    bool operator!=(Motor&);

    bool operator>(Motor&);
    bool operator<(Motor&);


};



#endif