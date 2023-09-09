#include <iostream>

using namespace std;

int main() {
    string a;
    char input[6];
    string c;

    getline(cin, a);
    cin.get(input, 6, '\n');



    for (size_t i = 0; i < a.length(); i++)
    {
        cout << a[i];
    }
    
    cout << endl;

    cin.clear();

    for (size_t i = 0; i < 6; i++)
    {
        cout << input[i];
    }
    
    cout << endl;

    cout << a[5] << endl;

    cout << input[5] << endl;




}