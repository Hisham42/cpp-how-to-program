#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <cstdlib>
#include <array>
using namespace std;

void pickVictor(vector<char> &, int);

int main() {


enum class Hash{TWO=2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};

    string userInput;

    getline(cin, userInput);

    vector<char> test2;
    vector<char> test3;
    vector<char> test4;
    vector<char> test5;
    vector<char> test6;
    vector<char> test7;
    vector<char> test8;
    vector<char> test9;    

    pickVictor(test2, userInput[0] - '0');
    pickVictor(test3, userInput[1] - '0');
    pickVictor(test4, userInput[2] - '0');
    pickVictor(test5, userInput[3] - '0');
    pickVictor(test6, userInput[4] - '0');
    pickVictor(test7, userInput[5] - '0');
    pickVictor(test8, userInput[6] - '0');

    int z{1};

    ofstream hash("hash.txt", ios::out);

    for (size_t i = 0; i < test2.size(); i++)
    {
        for (size_t j = 0; j < test3.size(); j++)
        {
            for (size_t k = 0; k < test4.size(); k++)
            {
                for (size_t l = 0; l < test5.size(); l++)
                {
                    for (size_t m = 0; m < test6.size(); m++)
                    {
                        for (size_t n = 0; n < test7.size(); n++)
                        {
                            for (size_t o = 0; o < test8.size(); o++)
                            {
                            
                                hash << z << " - " << test2[i]
                                << test3[j] << test4[k] << test5[l]
                                << test6[m] << test7[n] << test8[o]
                                << endl;

                                z++;
                            
                                
                            }
                            
                        }
                        
                    }
                    
                }
                
            }
            
        }
        
    }
    hash.close();
    

}


void pickVictor(vector<char> &v, int UserInput) {

    vector<char> two{'A', 'B', 'C'};
    vector<char> three{'D', 'E', 'F'};
    vector<char> four{'G', 'H', 'I'};
    vector<char> five{'J', 'K', 'L'};
    vector<char> six{'M', 'N', 'O'};
    vector<char> seven{'P', 'Q', 'R', 'S'};
    vector<char> eight{'T', 'U', 'V'};
    vector<char> nine{'W', 'X', 'Y', 'Z'};

    switch (UserInput)
    {
    case 2:
        v = two;
        break;
    
    case 3:
        v = three;
        break;
    
    case 4:
        v = four;
        break;
    
    case 5:
        v = five;
        break;
    
    case 6:
        v = six;
        break;
    
    case 7:
        v = seven;
        break;
    
    case 8:
        v = eight;
        break;
    
    case 9:
        v = nine;
        break;
    
    default:
        break;
    }

}