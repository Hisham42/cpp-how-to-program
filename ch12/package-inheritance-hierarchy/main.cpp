#include "package.h"
#include "twodaypackage.h"
#include "overnightpackage.h"
#include <vector>

int main() {

    

    TwoDayPackage b("Ahmed", "2 Mostshat St", "Tanta",
    "Gharbia", "31111", 22, 1.75,
    "Hisham", "72 Alkzafy St", "Tanta",
    "Gharbia", "38457", 15);

    OvernightPackage c("Ahmed", "2 Mostshat St", "Tanta",
    "Gharbia", "31111", 22, 1.75,
    "Hisham", "72 Alkzafy St", "Tanta",
    "Gharbia", "38457", 2);

    
    vector<Package*> packages{&b, &c};
    double totalCost;

    for (Package* i : packages)
    {
        cout << i->getAddressS() << endl;
        cout << i->getAddressR() << endl;

        i->displayPackage();

        cout << i->calculateCost() << endl;

        cout << "---------" << endl;
        totalCost += i->calculateCost();
    }
    

    cout << "Total Cost = " << totalCost << endl;
    




}