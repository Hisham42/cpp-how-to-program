#include <iostream>
#include <math.h>

using namespace std;

int main() {
    /*(Calculating a Sphere’s Circumference, Area and Volume) Write a program that reads the
radius of a sphere (as a double value) and computes the circumference, area and volume of the
spheres. Use the value 3.14159 for π.*/

    double radius{0};

    cout << "Enter sphere radius: ";
    cin >> radius;
    
    const double BI = 3.14159;

    double circumference = 2 * BI * radius;

    double volume = static_cast<double>(4.0/3) * BI * pow(radius, 3);
    
    double area = 4 * BI * pow(radius, 2);


    cout << "\ncircumference: " << circumference;
    cout << "\nvolume: " << volume;
    cout << "\narea: " << area << endl;




}