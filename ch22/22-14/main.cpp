#include <iostream>

int main() {

    char s[100];

    std::cin.getline(s, 100);

    std::cout << s << std::endl;

    int l{0}, u{0};
    double t{0};

    for (size_t i = 0; i < 100; i++)
    {
        if (isalpha(s[i]))
        {
            if (isupper(s[i]))
            {
                u++;
            }
            else
                l++;

            t++;
            
        }
        
    }

    std::cout << "Upper = " << u / t * 100.00<< "%" << std::endl;
    std::cout << "Lower = " << l / t * 100.00 << "%" << std::endl;
    
}