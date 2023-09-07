#include <iostream>
#include <iomanip>

using namespace std;

int main() {


    ios_base::fmtflags originalFormat{cout.flags()};

    cout << cin.eof() << endl;
    double a = 400.5;
    cout << left << showpoint << setprecision(15) << a << endl;






    char b[10];

    //read char by char
    // till i reach 'p' or 10
    // then check if there is a delimiter and discard it

    int i{0};

    while (i < 10)
    {
        char d = cin.get();

        if (d == 'p')
        {
            break;
        }

        if (d != ' ' && d != ',' && d != '\n')
        {
            b[i] = d;
            i++;
        }
        
    }

    for (size_t i = 0; i < 10; i++)
    {
        cout << b[i] << endl;
    }

    cout.flags(originalFormat);

    double numb = 1.234;

    
    cout << right << setw(9) << setfill('0') << numb << endl;
    
    

    

    
    
    
}