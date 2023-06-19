#include <iostream>
using namespace std;
double passByValue(double x);
void passByReference(double& x);

int main(){

    double x{3};

    cout << passByValue(x) << endl;
    
    cout << x << endl;
    passByReference(x);
    cout << passByValue(x) << endl;


}


double passByValue(double x){
    return 3*x;
}

void passByReference(double& x){
    x *= 3;
}