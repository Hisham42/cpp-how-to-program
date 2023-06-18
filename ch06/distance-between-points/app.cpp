#include <iostream>
#include <math.h>
using namespace std;

double distance(double x1, double y1, double x2, double y2);

int main() {
   
    cout << distance(0, 2, 3, 6) << endl;

}


double distance(double x1, double y1, double x2, double y2) {
    double x3 = x2 - x1;
    double y3 = y2 - y1;


    return sqrt(pow(x3, 2) + pow(y3, 2));
    
}