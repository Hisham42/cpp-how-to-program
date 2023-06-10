#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double calculateCharges(double hours);
double hourCalculator(double hours);

int main() {

    double hours1{0}, hours2{0}, hours3{0};
    
    cout << "Please enter hours for 3 cars " << "\n";
        cin >> hours1;
        cin >> hours2;
        cin >> hours3;

    cout << "Cars" << setw(10) << "hours" << setw(10) << "Charges" << endl;

    

        
    cout << 1 << setw(10) << hours1 << setw(10) << calculateCharges(hours1) << endl;
    cout << 2 << setw(10) << hours2 << setw(10) << calculateCharges(hours2) << endl;
    cout << 3 << setw(10) << hours3 << setw(10) << calculateCharges(hours3) << endl;
    
    
    

}

double calculateCharges(double hours){

    double charges{0};

    if (hours >= 0 && hours <= 3)
    {
        charges += 20.0;
    }

    else if (hours > 3)
    {
        charges = 20 + (hourCalculator(hours)) * 5;
    }


    return charges;
}

double hourCalculator(double hours){

    double totalHours{hours - 3};

    if (totalHours >=6)
    {
        return 6.0;
    }
    else
    {
        
        return (ceil((totalHours)));
        
    } 
}