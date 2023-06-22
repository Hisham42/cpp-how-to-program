// Fig. 6.9: fig06_09.cpp
// Craps simulation.
#include <array>
#include <iostream>
#include <cstdlib> // contains prototypes for functions srand and rand
#include <ctime> // contains prototype for function time
using namespace std;

unsigned int rollDice(); // rolls dice, calculates and displays sum

int main() {
   // scoped enumeration with constants that represent the game status 
   enum class Status {CONTINUE, WON, LOST}; // all caps in constants
   array <int, 20> storageWon;
   array <int, 20> storageLost;
   srand(static_cast<unsigned int>(time(0)));

   for (size_t i = 0; i < 1000; i++)
   {
      
      
      // randomize random number generator using current time
      

      unsigned int myPoint{0}; // point if no win or loss on first roll
      Status gameStatus; // can be CONTINUE, WON or LOST
      unsigned int sumOfDice{rollDice()}; // first roll of the dice

      // determine game status and point (if needed) based on first roll
      switch (sumOfDice) {
         case 7: // win with 7 on first roll
         case 11: // win with 11 on first roll           
            gameStatus = Status::WON;
            storageWon[0] += 1;
            break;
         case 2: // lose with 2 on first roll
         case 3: // lose with 3 on first roll
         case 12: // lose with 12 on first roll             
            gameStatus = Status::LOST;
            storageLost[0] += 1;
            break;
         default: // did not win or lose, so remember point
            gameStatus = Status::CONTINUE; // game is not over
            myPoint = sumOfDice; // remember the point
            cout << "Point is " << myPoint << endl;
            break; // optional at end of switch  
      }


      int roll{0};

      // while game is not complete
      while (Status::CONTINUE == gameStatus) { // not WON or LOST
         sumOfDice = rollDice(); // roll dice again
         roll += 1;
         // determine game status
         if (sumOfDice == myPoint) { // win by making point
            gameStatus = Status::WON;
            if (roll > 19)
            {
               storageWon[19] += 1;
            }
            else {
               storageWon[roll] += 1;
            }
            
            
         }
         else {
            if (sumOfDice == 7) { // lose by rolling 7 before point
               gameStatus = Status::LOST;
               if (roll > 19)
               {
                  storageLost[19] += 1;
               }
               else {
                  storageLost[roll] += 1;
               }
            }
         }
      }

      // display won or lost message
      if (Status::WON == gameStatus) {
         cout << "Player wins" << endl;
        
      }
      else {
         cout << "Player loses" << endl;
         
      }
   }


   float won{0}, lost{0};

   cout << "\nWon\n";
   for (size_t i = 0; i < storageWon.size(); i++)
   {
      won += storageWon[i];
      cout << i + 1 << " : " << storageWon[i] << endl;
   }

   cout << "\nLost\n";
   for (size_t i = 0; i < storageLost.size(); i++)
   {
      lost += storageLost[i];
      cout << i + 1 << " : " << storageLost[i] << endl;
   }
    
   cout << "Chances are: " << won/10 << "% won and " << lost/10 << "% " << "loss" << endl;
   cout << "Average games: " << won/20 << " or " << lost/20 << endl;


}
// roll dice, calculate sum and display results
unsigned int rollDice() {
   int die1{1 + rand() % 6}; // first die roll
   int die2{1 + rand() % 6}; // second die roll
   int sum{die1 + die2}; // compute sum of die values

   // display results of this roll
   cout << "Player rolled " << die1 << " + " << die2
      << " = " << sum << endl;
   return sum;
}

/**************************************************************************
 * (C) Copyright 1992-2017 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/
