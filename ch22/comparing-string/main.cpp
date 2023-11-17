#include <iostream>
#include <cstring>

void compare(char* c1, char* c2, int size) {
    char* temp1 = new char[size];
    char* t1 = temp1;
    char* temp2 = new char[size];
    char* t2 = temp2;

    for (size_t i = 0; i < size; i++)
    {
        *temp1 = *c1;
        *temp2 = *c2;
        temp2++;
        c2++;
        temp1++;
        c1++;
    }

    if (strcmp(t1, t2) == 0)
    {
        std::cout << t1 << " == " << t2 << std::endl;
    }
    else if (strcmp(t1, t2) > 0)
    {
        std::cout << t1 << " > " << t2 << std::endl;
    }
    else
        std::cout << t1 << " < " << t2 << std::endl;
}

int main()
 {
    char* c1 = new char[20];
    char* c2 = new char[20];


    std::cin.getline(c1, 20);
    std::cin.getline(c2, 20);

    compare(c1, c2, 5);

}