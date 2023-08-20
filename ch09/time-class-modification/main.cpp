#include "Time.h"



int main()
{
    Time clock (12, 59, 30);
    cout << clock.toStandardString() << endl;
    cout << clock.toNumberOfSeconds() << endl;
}