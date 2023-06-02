/*(Validating User Input) The examination-results program of Fig. 4.14 assumes that any val-
ue input by the user that’s not a 1 must be a 2. Modify the application to validate its inputs. On any
input, if the value entered is other than 1 or 2, keep looping until the user enters a correct value.*/


// Fig. 4.14: Analysis.cpp
// Analysis of examination results using nested control statements.

#include <iostream>
using namespace std;

int main() {
    unsigned int passes{0};
    unsigned int failures{0};
    unsigned int studentCounter{1};



    while (studentCounter <= 10) {
        cout << "Enter result (1 = pass, 2 = fail): ";
        int result;
        cin >> result;

        if (result == 1) {
            passes = passes + 1;
            studentCounter = studentCounter + 1;
        }
        else if (result == 2) {
            failures = failures + 1;
            studentCounter = studentCounter + 1;
        }
        else
        {
            cout << "Please Enter 1 or 2" << "\n";
        }
    }
    
    cout << "Passed: " << passes << "\nFailed: " << failures << endl;
    if (passes > 8) {
        cout << "Bonus to instructor!" << endl;
    }
}