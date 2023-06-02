#include <iostream>

using namespace std;


int main() {

    unsigned int lap{0};
    float sponsorshipRate{0};
    float sponsorshipContribution{0};

    while (lap != -1)
    {
        cout << "Enter laps calculated: ";
        cin >> lap;
        if (lap != -1)
        {
            cout << "Enter Sponsorship Rate: ";
            cin >> sponsorshipRate;
            if (lap <= 40)
            {
                sponsorshipContribution = lap * sponsorshipRate;
            }

            // if lap > 40
            // calculate sponsorship contribution for 40
            // calculate sponsorship for the rest (adding the increment)

            else
            {
                sponsorshipContribution = sponsorshipRate * 40;
                sponsorshipRate = 1.5 * sponsorshipRate;
                lap = lap - 40;
                sponsorshipContribution = sponsorshipContribution + sponsorshipRate * lap;
            }
            
            cout << "Student Contribution: " << sponsorshipContribution << "\n\n";


        }
    }
    

}