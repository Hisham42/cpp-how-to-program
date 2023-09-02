#include "account.h"
#include "checking-account.h"
#include "saving-account.h"

int main() {
    Account Hisham(7.2);
    cout << "$" << Hisham.getBalance() << endl;
    Hisham.credit(620);
    Hisham.debit(7.2);
    cout << "$" << Hisham.getBalance() << endl;



    CheckingAccount Ahmed(7.5, .2);
    cout << "$" << Ahmed.getBalance() << endl;
    
    Ahmed.debit(7.2);
    cout << "$" << Ahmed.getBalance() << endl;

    SavingAccount Shosha(500.5, .03);
    cout << "Interest is: " << Shosha.calculateInterest() << endl;
    cout << "$" << Shosha.getBalance() << endl;
    
    Shosha.credit(Shosha.calculateInterest());
    cout << "$" << Shosha.getBalance() << endl;




}