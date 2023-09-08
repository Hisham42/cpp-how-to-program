#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main() {

    string f, l, y;

    cout << "First Name: ";
    cin >> f;

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Last Name: ";
    cin >> l;
    cout << "Year of birth: ";
    cin >> y;



    cout << right << setw(10) << f << setw(10) << l << setw(10) <<  y << '\n' << endl;

}