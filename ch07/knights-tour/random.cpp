#include <iostream>
#include <random>

using namespace std;

int main() {
    
    default_random_engine engine(static_cast<unsigned int>(time(0)));

    uniform_int_distribution <unsigned int> randomNum(0, 8);

    for (size_t i = 0; i < 10; i++)
    {
        cout << randomNum(engine) << endl;
    }
    

}