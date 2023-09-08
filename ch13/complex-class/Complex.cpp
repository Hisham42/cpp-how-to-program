#include "Complex.h"



Complex::Complex(/* args */)
{
    /**/
}

Complex::~Complex()
{
}



ostream& operator<<(ostream& out, Complex& c) {

    if (cin.good())
    {
        out << c.real << " " <<  c.sign << " " << abs(c.imaginary) << "i" << endl;
    }
    else
    {
        cout << "Error" << endl;
    }
    

    return out;

}


istream& operator>>(istream& in, Complex& c) {

    string a;

    getline(in, a);

    if (a.length() == 6)
    {
        if (a[0] - '0' >= 0 && a[4] - '0' >= 0  && (a[2] == '+' || a[2] == '-') && a[5] =='i')
        {
            if (a[2] == '-')
            {
                c.imaginary = 0 - (a[4] - '0');
            }
            else
            {
                c.imaginary = a[4] - '0';
            }
            c.sign = a[2];
            c.real = a[0] - '0';
            
        }
        else
        {
            in.clear(ios::failbit);
        }
    }
    else if (a.length() == 7)
    {
        if (a[1] - '0' >= 0 && a[5] - '0' >= 0  && (a[3] == '+' || a[3] == '-') && a[6] =='i')
        {
            if (a[3] == '-')
            {
                c.imaginary = 0 - (a[5] - '0');
            }
            else
            {
                c.imaginary = a[5] - '0';
            }

            
            c.sign = a[3];
            c.real = 0 - (a[1] - '0');
            
        }
        else
        {
            in.clear(ios::failbit);
        }
    }

    else
    {
        in.clear(ios::failbit);
    }
    
    return in;

}
