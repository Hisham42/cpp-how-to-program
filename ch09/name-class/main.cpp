#include <iostream>
#include "name.h"

using namespace std;


int main()
{
    Name person1("Hisham", "Mohamed", "Mousa", "Hallo");


    person1.setFirst("Mohamed");

    cout << person1.toString() << endl;

    cout << person1.getFirst() << endl;

}