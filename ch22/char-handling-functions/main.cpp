#include <iostream>

bool isDigit(char a) {
    if (a >= 48 && a <= 57 )
    {
        return true;
    }
    return false;
    
}

bool isLower(char a) {
    if ((a >= 97 && a <= 122))
    {
        return true;
    }
    return false;
}

bool isUpper(char a) {
    if ((a >= 65 && a <= 90))
    {
        return true;
    }
    return false;
}

char toLower(char a) {

    if (isUpper(a))
    {
        return a + 32;
    }
    else
        return a;
}

char toUpper(char a) {
    
    if (isLower(a))
    {
        return a - 32;
    }
    else
        return a;
}

bool isSpace(char a) {
    
    if (a == ' ')
    {
        return true;
    }
    else
        return false;
}

bool isCntrl(char a) {
    
    if (a == '\n' || a == ' ' || a == '\f' || a == '\r' || a == '\t' || a == '\v')
    {
        return true;
    }
    else
        return false;
}



bool isPrint(char a) {
    
    if (a > 32 && a < 127)
    {
        return true;
    }
    else
        return false;
}

bool isGraph(char a) {
    
    if (a > 32 && a < 127 && !isSpace(a))
    {
        return true;
    }
    else
        return false;
}

bool isAlpha(char a, int b1=65, int b2=90) {
    if ((a >= b1 && a <= b2) || isLower(a))
    {
        return true;
    }
    return false;
    
}

bool isAlnum(char a) {
    if (isAlpha(a) || isDigit(a))
    {
        return true;
    }
    return false;
    
}

bool isHexa(std::string a) {
    for (size_t i = 0; i < a.size(); i++)
    {
        if (!isDigit(a[i]) && !isAlpha(a[i], 65, 70))
        {
            return false;
        }
        
    }
    return true;
    
    
}

bool isPunct(char a) {
    
    if (!isAlnum(a) && !isSpace(a))
    {
        return true;
    }
    else
        return false;
}

int main() {

    std::cout << std::boolalpha << isDigit('2') << std::endl;
    std::cout << std::boolalpha << isDigit('a') << std::endl;

    std::cout << std::boolalpha << isAlpha('2') << std::endl;
    std::cout << std::boolalpha << isAlpha('a') << std::endl;

    std::cout << std::boolalpha << isAlpha('2') << std::endl;
    std::cout << std::boolalpha << isAlpha('A') << std::endl;

    std::cout << std::boolalpha << isAlnum('2') << std::endl;
    std::cout << std::boolalpha << isAlnum('A') << std::endl;

    std::cout << std::boolalpha << isHexa("AF") << std::endl;
    std::cout << std::boolalpha << isHexa("FH") << std::endl;

    std::cout << std::boolalpha << isLower('F') << std::endl;
    std::cout << std::boolalpha << isLower('f') << std::endl;

    std::cout << std::boolalpha << isUpper('F') << std::endl;
    std::cout << std::boolalpha << toLower('A') << std::endl;

    std::cout << std::boolalpha << toUpper('f') << std::endl;
    std::cout << std::boolalpha << isSpace(' ') << std::endl;

    std::cout << std::boolalpha << isCntrl('\f') << std::endl;
    std::cout << std::boolalpha << isPunct('`') << std::endl;

    std::cout << std::boolalpha << isPrint('p') << std::endl;
    std::cout << std::boolalpha << isGraph('~') << std::endl;

    

}