#include <iostream>
using namespace std;

int main(){

    
    float workingHours{0};

    while (workingHours != -1)
    {
        float breakHours{2};

        cout << "Enter number of hours worked (-1 to end): ";
        cin >> workingHours;

        /* code */
        if (workingHours > 0) 
        {
            
            breakHours = breakHours + .1 * workingHours;

            cout << "Accrued leave: " << breakHours << "\n";

        }
    }
    


}