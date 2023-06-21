#include <iostream>
#include <array>
#include <random>
using namespace std;




const int VALUES = 11;

int main() {

    default_random_engine engine(static_cast<unsigned int>(time(0)));

    uniform_int_distribution <unsigned int> randomInt(1,6);


    array <int, VALUES> storage;

    for (long i = 0; i < 36'000'000; i++)
    {  
        storage[randomInt(engine) + randomInt(engine) - 2] += 1;
    }


    for (size_t j = 0; j < VALUES; j++)
    {
        cout << j + 2 << " >> " << storage[j] << endl;
    }
    
    
}





