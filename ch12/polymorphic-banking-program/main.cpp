#include "account.h"
#include "checking-account.h"
#include "saving-account.h"
#include <vector>
#include <typeinfo>

int main() {


    CheckingAccount Ahmed(1000, .2);

   



    SavingAccount Shosha(1000, .03);
    

  


    vector<Account*> accounts{&Ahmed, &Shosha};


    

    double credit{0};
    double debit{0};

    for (Account* i : accounts)
    {


        cout << "Withdraw Amount: ";
        cin >> debit;
        i->debit(debit);

        cout << "Deposit Amount: ";
        cin >> credit;
        i->credit(credit);

        



        if (dynamic_cast<SavingAccount*>(i) != nullptr)
        {
            i->credit(i->calculateInterest());
        }



        cout << i->getBalance() << endl;



        cout << "---------------" << endl;
        

    }




}