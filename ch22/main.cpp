// Ex. 22.29: Ex22_29.cpp
// What does this program do?
#include <iostream>
using namespace std;

bool mystery3(const char*, const char*); // prototype

int main() {
    char string1[80], string2[80];

    cout << "Enter two strings: ";
    cin >> string1 >> string2; // enter 2 strings
    cout << "The result is " << mystery3(string1, string2) << endl;
}

    // What does this function do?
    bool mystery3(const char* s1, const char* s2) {
        for (; *s1 != '\0' && *s2 != '\0'; ++s1, ++s2) {
            if (*s1 != *s2) {
                return false;
        }
    }

    return true;
}
