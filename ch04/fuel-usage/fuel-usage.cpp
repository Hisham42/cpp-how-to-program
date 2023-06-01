/*Drivers are concerned with the amount of fuel used by their motor vehicles.
One driver has kept track of several trips by recording kilometers driven and liters of fuel used for
each trip. Develop a C++ program that uses a while statement to input the kilometers driven and
liters of petrol used for each trip. The program should calculate and display the kilometers per liter
obtained for each trip and print the combined kilometers per liter obtained for all tankfuls up to
this point.*/

/*
initialize fuel_usage (l)
initialize trip_length (KM)
While KM is not -1
    Enter kilometers driven (-1 to quit): userInput
    Enter liters used: userInput
    Kms per liter this trip: ?
    Total kms per liter: ?

*/
#include <iostream>
using namespace std;

int main(){


    unsigned int fuelUsage{0};
    int kmDriven{0};
    
    unsigned int totalFuelUsage{0};
    unsigned int totalKmDriven{0};

    double totalAverage{0};


    while (kmDriven != -1)
    {
        /* code */
        double tripAverage{0};

        cout << "Enter kilometers driven (-1 to quit): ";
        cin >> kmDriven;

        if (kmDriven > 0)
        {
            /* code */
            cout << "Enter liters used: ";
            cin >> fuelUsage;

            tripAverage = static_cast<double>(kmDriven) / fuelUsage;

            totalFuelUsage += fuelUsage;
            totalKmDriven += kmDriven;

            totalAverage = static_cast<double>(totalKmDriven) / totalFuelUsage;


            cout << "Kms per liter this trip: " << tripAverage;

            cout << "\nTotal kms per liter: " << totalAverage << "\n\n";
        }
        

        
    
    }
    
    


}


