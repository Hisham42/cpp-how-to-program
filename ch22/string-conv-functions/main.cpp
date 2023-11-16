#include <iostream>




bool isLower(char a) {
    if ((a >= 97 && a <= 122))
    {
        return true;
    }
    return false;
}

bool isAlpha(char a, int b1=65, int b2=90) {
    if ((a >= b1 && a <= b2) || isLower(a))
    {
        return true;
    }
    return false;
    
}

bool isDigit(char a) {
    if (a >= 48 && a <= 57 )
    {
        return true;
    }
    return false;
    
}

bool isHexa(char a) {
    
    if (isDigit(a))
    {
        return true;
    }
    else
    {
        if ((a >= 65 && a <= 70) || (a >= 97 && a <= 102))
        {
            return true;
        }
    }

    return false;
    
    
    
}

int htod(char a) {

    if (islower(a))
    {
        a = toupper(a);

    }
    
    int s[6] = {10, 11, 12, 13, 14, 15};

    if (isHexa(a) && isAlpha(a))
    {
        return s[a - 65];
    }
    else
    {
        return a - '0';
    }
    
}

int ctoi(char c) {
    return c - '0';
}

double stod(const char* s) {

    // determine the size
    int size{0};
    int decimalSign{0};
    while (s[size] != '\0')
    {
        if (s[size] == '.')
        {
            decimalSign = size;
        }
        size++;
    }
    
    double d{0};
    if (decimalSign == 0)
    {
        decimalSign = size;
    }
    
    double k{1};

    for (int i = decimalSign - 1; i >= 0; i--, k*=10)
    {
        d += ctoi(s[i]) * k;
    }
    double j = 10.00;

    for (size_t i = decimalSign + 1; i < size; i++, j*=10)
    {
        d += ctoi(s[i]) / j;
    }


    return d;
}

int stoi(const char* s) {

    // determine the size
    int size{0};
    int decimalSign{0};
    while (s[size] != '\0')
    {
        if (s[size] == '.')
        {
            decimalSign = size;
        }
        size++;
    }

    if (decimalSign == 0)
    {
        decimalSign = size;
    }
    
    int d{0};

    int k{1};

    for (int i = decimalSign - 1; i >= 0; i--, k*=10)
    {
        d += ctoi(s[i]) * k;
    }
    


    return d;
}

long stol(const char* s) {

    // determine the size
    int size{0};
    int decimalSign{0};
    while (s[size] != '\0')
    {
        if (s[size] == '.')
        {
            decimalSign = size;
        }
        size++;
    }

    if (decimalSign == 0)
    {
        decimalSign = size;
    }
    
    long d{0};

    long k{1};

    for (int i = decimalSign - 1; i >= 0; i--, k*=10)
    {
        d += ctoi(s[i]) * k;
    }
    


    return d;
}



unsigned long strtoul(const char* s, char** p, int base=10) {

    int size{0};
    int decimalSign{0};

    while (s[size] != '\0')
    {
        if (!isHexa(s[size]))
        {
            *p = const_cast<char*>(s) + size;
            break;
        }
        
        if (s[size] == '.')
        {
            decimalSign = size;
        }
        size++;
    }

    long d{0};
    if (decimalSign == 0)
    {
        decimalSign = size;
    }
    
    int k{1};

    for (int i = decimalSign - 1; i >= 0; i--, k*=base)
    {
        d += htod(s[i]) * k;
    }


    return d;
}
int main() {
    // convert string to double    "12.4"  >>>> 12.4
    // 

    char a[] = "123hsad";

    char* k;

    std::cout << strtoul(a, &k, 8) * 2 << std::endl;

    std::cout << k << std::endl;



}