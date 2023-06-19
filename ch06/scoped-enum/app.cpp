#include <iostream>

using namespace std;

int main(){
    enum AccountType {SAVINGS, CHECKING, INVESTMENT};


    AccountType type;

    type = AccountType :: INVESTMENT;

    cout << type;


}