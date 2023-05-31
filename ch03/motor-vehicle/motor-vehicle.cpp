#include <iostream>
#include <string>
#include "motor-vehicle.h"


using namespace std;

int main(){
    MotorVehicle van("Egypt", "Diesel", 2002, "White", 2000);
    
    van.displayCarDetails();
}