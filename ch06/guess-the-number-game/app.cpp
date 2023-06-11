#include <iostream>
#include <cstdlib>
#include <random>

using namespace std;

int main() {

    char playAgain{'y'};

    
    

    cout << "I have a number between 1 and 1000."
        << "\n" << "Can you guess my number?";
    

    unsigned int user_input{0}, random{0};

    int i{0};

    
    

    

    while (true)
    {
        srand(static_cast<unsigned int>(time(0)));
        random = (1 + rand()) % 1000;
        
        
        if (playAgain == 'n')
        {
            break;
        }
        
        cout << "\n" << "Please type your first guess." << endl;

        
        
        while (true)
        {
            cin >> user_input;
            i++; 

            if (user_input == random)
            {

                if (i >= 10)
                {
                    cout << "Either you know the secret or you got lucky!";
                }

                if (i == 10)
                {
                    cout << "\n" << "Ahah! You know the secret!";
                }
                else
                {
                    cout << "\n" << "You should be able to do better!";
                }
                
                cout << "\n" << "Would you like to play again (y or n)?\n";



                cin >> playAgain;

                break;
                

            }
            

            if (user_input > random)
            {
                cout << "Too high" << endl;
            }
            else if (user_input < random)
            {
                cout << "Too low" << endl;
            }
            
  
        }
    }
    
    
}