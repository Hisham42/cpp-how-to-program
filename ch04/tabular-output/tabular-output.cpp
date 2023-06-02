#include <iostream>
using namespace std;


int main () {



    unsigned int n{1}, a{5}, b{10}, c{15};


    cout << "N" << "\t\t" << "5*N" << "\t\t" << "10*N" << "\t\t" << "15*N" << "\n";

    while (n != 13)
    {
        cout << n << "\t\t" << a*n << "\t\t" << b*n << "\t\t" << c*n << "\n";
        n++;

    }
}