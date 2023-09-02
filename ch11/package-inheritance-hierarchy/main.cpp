#include "package.h"
#include "twodaypackage.h"
#include "overnightpackage.h"

int main() {

    Package a("Ahmed", "2 Mostshat St", "Tanta",
    "Gharbia", "31111", 22, 1.75,
    "Hisham", "72 Alkzafy St", "Tanta",
    "Gharbia", "38457");

    a.displayPackage();


    TwoDayPackage b("Ahmed", "2 Mostshat St", "Tanta",
    "Gharbia", "31111", 22, 1.75,
    "Hisham", "72 Alkzafy St", "Tanta",
    "Gharbia", "38457", 15);

    OvernightPackage c("Ahmed", "2 Mostshat St", "Tanta",
    "Gharbia", "31111", 22, 1.75,
    "Hisham", "72 Alkzafy St", "Tanta",
    "Gharbia", "38457", 2);

    
    b.displayPackage();

    c.displayPackage();



}