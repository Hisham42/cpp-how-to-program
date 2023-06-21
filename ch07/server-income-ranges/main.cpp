#include <iostream>
#include "server.h"
#include <array>
#include <iomanip>

using namespace std;



int main() {

    /*char currency{'$'};

    cout << "Please Enter Currency: " ;
    cin >> currency; */
    

    Server hisham{10,20};
    Server ahmed{12,15};
    Server mohamed{22,12};
    Server mousa{10,50};
    Server hadil{11,20};
    Server shosha{34,10};
    Server ashraf{24,8};
    Server carem{32,3};


    array <int, 8> servers{hisham.totalPaid(), ahmed.totalPaid(), mohamed.totalPaid(),
    mousa.totalPaid(), hadil.totalPaid(), shosha.totalPaid(), ashraf.totalPaid(), carem.totalPaid()};

    array <int, 9> counters;
    
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 20; j < 100; j += 10)
        {
            if (servers[i] / j == 0) {
                counters[(j - 20)/10] += 1;
                break;
            }
            if (servers[i] > 100)
            {
                counters[8] +=1;
                break;
            }
            

            
        }
        
    }
    
    int l{0};


    cout << "Range" << setw(24) << "Value" << endl;

    for (size_t k = 20; k < 100; k += 10)
    {
        

        cout << k << "-" << k+9 << setw(20) << counters[l] << endl;

        l++;
    }

    cout << "100" << " and over"<< setw(13) << counters[8] << endl;
    
    
        
        
        
    




    
}