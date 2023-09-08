#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    int h;

    cin >> h;

    cout << showbase << dec << h << endl;
    cout << showbase << oct << h << endl;

    cout << showbase << hex << h << endl;


}