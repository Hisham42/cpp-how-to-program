#include <iostream>

#include <string>
#include "motor.h"


using namespace std;

int main() {

    Motor van("Masr", "BMW", 2030, "Red", 6000);

    Motor van2("Masr", "BMW", 2010, "Red", 6000);
    
    if (van == van2)
    {
        cout << "Operator == works perfectly." << endl;
    }

    if (van != van2)
    {
        cout << "Operator != works perfectly." << endl;
    }

    if (van > van2)
    {
        cout << "van is older than van2"<< endl;
    }

    if (van < van)
    {
        cout << "van2 is older than van"<< endl;
    }

    cout << van;
    
    
    
}