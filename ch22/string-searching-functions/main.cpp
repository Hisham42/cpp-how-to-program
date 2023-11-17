#include <iostream>
#include <cstring>


int size(const char* a) {
    
    char* temp = const_cast<char*>(a);
    int i = 1;

    while (*temp != '\0')
    {
        i++;
        temp++;
    }

    return i;
}
char* strchr(const char* s, char a) {

    char* temp = const_cast<char*>(s);

    int i{0};
    while (i < size(s))
    {
        if (*temp == a)
        {
            return temp;
        }
        
        temp += 1;
    }

    return nullptr;

}

bool checkMatching(char* t1, char* t2) {

    char* std2 = t2;
    int i{0};
    while (i < size(t2)) {
        if (*t1 != *t2)
        {
            return false;
        }
        t1 += 1;
        t2 += 1;
    }


    return true;
}

char* strstrH(const char* s1, const char* s2) {

    

    char* temp = const_cast<char*>(s1);
    char* temp2 = const_cast<char*>(s2);

    while (*temp != '\0')
    {
        if (*temp == *s2)
        {
            if(checkMatching(temp, temp2))
            {
                std::cout << s2 << " is found in " << s1 << std::endl;

                return temp;
            }
            else
            {
                std::cout << s2 << " is not found in "  << s1 << std::endl;
            }
            
        }
        
        temp += 1;
    }


    return nullptr;

}



int main() {
    const char* a = "Ahmedm mohamed Ahmeda";

    const char* c = "Ahmeda";

    char* b = strchr(a, 'm');

    char* d = strstrH(a, c);


}