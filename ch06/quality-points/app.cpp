#include <iostream>
#include <cstdlib>
int toss();

using namespace std;

int main() {

    int y{0};
    srand(static_cast<unsigned int>(time(0)));

    for (int i = 1; i <= 100; i++)
    {
        y += toss();
    }

    cout << y << endl;
     

}

int toss(){
    
    int x = (1 + rand() % 2);
    if (x == 1)
    {
        return 1;
    }
    else
        return 0;
}