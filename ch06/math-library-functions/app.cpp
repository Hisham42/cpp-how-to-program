#include <iostream>
#include <iomanip> 
#include <math.h>

using namespace std;


double math_fabs(double number);
double math_floor(double number);
double math_fmod(double x, double y);
double math_pow(double x, double y);

int main() {
    cout << "math_fabs(-8.76) = " << setprecision(3) << math_fabs(-8.76) << endl;
    cout << "math_floor(10.2) = " << math_floor(10.2) << endl;
    cout << "math_floor(-10.8) = " << math_floor(-10.8) << endl;
    cout << "math_fmod(2.6, 1.2) = " << math_fmod(2.6, 1.2) << endl;
    cout << "math_fmod(4.8, 1.6) = " << math_fmod(4.8, 1.6) << endl;
    cout << "math_pow(3, 5) = " << math_pow(3, 5) << endl;
    cout << "math_pow(2, 7) = " << math_pow(2, 7) << endl;
    cout << "math_pow(9, .5) = " << math_pow(9, .5) << endl;


}

double math_fabs(double number) {
    if (number == 0)
    {
        return 0.0;
    }
    else if (number < 0)
    {
        return number * -1;
    }
    else
    return number;
    
}


double math_floor(double number) {

    if (number >= 0)
    {
        long number1 = number / 1;
        return number1 * 1.0;
    }
    else
    {
        long number1 = number / 1;
        return (number1 - 1) * 1.0;
    }

    
}


double math_fmod(double x, double y) {

    long x1 = x * 100;
    long y1 = y * 100;

    if (x1 % y1 == 0)
    {
        return 0;
    }
    else
    {

        double z = (x) / (y);

        z = z - static_cast<long>(z);

        z = z * 100; // 16
        z = z + 5; // 16 + 5 = 21

        z = static_cast<long>(z / 10);

        z = z / 10.0;
        
        return z;

    }
}

double math_pow(double x, double y) {

    if (y == 0)
    {
        return 1;
    }
    
    if (y == 0.5)
    {
        return sqrt(x);
    }
    
    else if (y == 1)
    {
        return x;
    }

    else
    {
        return x * math_pow(x, y-1);
    }
    


}