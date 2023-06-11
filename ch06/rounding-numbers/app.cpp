#include <iostream>
#include <math.h>
using namespace std;

double roundToInteger(double number);
double roundToTenths(double number);
double roundToHundredths(double number);
double roundToThousandths(double number);

int main(){
    float y;
    float x;

    for (size_t i = 0; i < 5; i++)
    {
        cin >> x;

        

        cout << "rounded is: " << roundToInteger(x) << " - " << roundToTenths(x) 
        << " - " << roundToHundredths(x) << " - " << roundToThousandths(x) << endl;
    }
    
}

double roundToInteger(double number) {
    return floor(number + 0.5);
}

double roundToTenths(double number) {
    return floor(number * 10 + 0.5) / 10;
}

double roundToHundredths(double number) {
    return floor(number * 100 + 0.5) / 100;
}

double roundToThousandths(double number) {
    return floor(number * 1000 + 0.5) / 1000;
}