#include <iostream>
using namespace std;

inline double circleArea(double r){
    return 3.14 * r * r;
}


int main() {
    int r{0};
    cout << "Enter Radius: " << endl;
    cin >> r;
    cout << circleArea(r) << endl;



}