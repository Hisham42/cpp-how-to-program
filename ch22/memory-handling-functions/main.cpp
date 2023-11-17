#include <iostream>

void memcpy(char* s1, const char* s2, size_t n) {

    char* temp = const_cast<char*>(s2);

    for (size_t i = 0; i < n; i++)
    {
        *s1 = *temp;
        s1 = s1 +1;
        temp++;
    }

}

int main() {
    char s1[17] {};
    char s2[]{"This is the end."};

    memcpy(s1, s2, 17);

    std::cout << s1 << std::endl;
}