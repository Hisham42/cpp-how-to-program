#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    int l, u;

    cout << "Lower limit: ";
    cin >> l;
    cout << "Upper limit: ";
    cin >> u;

    for (size_t i = l; i < u + 1; i++)
    {
        cout << showbase << setw(10) << dec << i << setw(10) << oct << i << setw(10) << hex << i << endl;  
    }
    


}