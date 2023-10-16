#include <iostream>

template<typename T>
bool isEqualTo(T first, T second) {

    bool a;

    if (first == second)
       a = true;
    else 
        a = false;

    std::cout << std::boolalpha << a << std::endl;
    return a;
}

class Hint
{
private:
    int a{0};
public:
    Hint(int=0);
    ~Hint();
    bool operator==(Hint b) {
        if (a == b.a)
            return true;
        else
            return false;


    }
};

Hint::Hint(int s)
{
    a = s;
}

Hint::~Hint()
{
}


int main() {

    isEqualTo(7.2f, 7.2f);

    Hint a;
    Hint b(2);
    isEqualTo(a, b);

}