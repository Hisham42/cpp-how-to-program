#include "integerset.h"

int main()
{
    Integerset a({3, 30, 100});

    Integerset b({30, 60, 99});

    a.unionThis(b).printInts();
    a.IntersectThis(b).printInts();


    Integerset c({20, 30, 40});
    Integerset d({20, 30, 40});



    c.isEqualTo(d);

    int arr[] = {20, 30, 40, 12, 23, 60, 70, 9823};

    Integerset e(arr);
    e.printInts();

}