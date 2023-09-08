#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>
using namespace std;

int main() {
    
    vector<double> ints;
    double a;

    while (true)
    {
        cin >> a;

        if (cin.good())
        {
            ints.push_back(a);
        }

        else
        {
            cin.clear();
            break;
        }
        
    }

    double mean, median, standardDeviation, min, max, sum{0}, count{0};

    min = ints[0];
    max = ints[0];

    for (size_t i = 0; i < ints.size(); i++)
    {
 
        if (ints[i] < min)
        {
            min = ints[i];
        }

        if (ints[i] > max)
        {
            max = ints[i];
        }
        
        sum += ints[i];
        count++;
    }

    mean = sum / count;

    double total{0};
    for (size_t i = 0; i < ints.size(); i++)
    {
        total += pow((ints[i] - mean), 2);
    }

    
    total /= ints.size() - 1;

    standardDeviation = sqrt(total);
    

    if (ints.size() % 2 == 0)
    {
        median = (ints[ints.size() / 2 - 1] + ints[ints.size() / 2]) / 2;
    }
    else
    {
        median = ints[ints.size() / 2];
    }
    
    cout << fixed << setprecision(2) << "mean: " << mean
    << "\nmedian: " << median
    << "\nstandard deviation: " << standardDeviation
    << "\nminimum: " << min
    << "\nmaximum: " << max << endl;


}