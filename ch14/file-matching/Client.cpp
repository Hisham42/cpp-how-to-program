#include "Client.h"

Client::Client(
    int accNum, const string& nam, const string& phone,
    const string& con, double bal)
{
    setAccountNumber(accNum);
    setName(nam);
    setPhone(phone);
    setCountry(con);
    setBalance(bal);
}

Client::~Client()
{
}

// Setters

void Client::setAccountNumber(int accNum) {
    accountNumber = accNum;
}

void Client::setName(const string& nam) {

    size_t length{nam.size()};
    length = (length < 20 ? length : 19);
    nam.copy(name, length);
    name[length] = '\0';

}

void Client::setPhone(const string& phone) {
    
    size_t length{phone.size()};
    length = (length < 20 ? length : 19);
    phone.copy(telephoneNumber, length);
    telephoneNumber[length] = '\0';

}

void Client::setCountry(const string& con) {
    
    size_t length{con.size()};
    length = (length < 20 ? length : 19);
    con.copy(country, length);
    country[length] = '\0';
}

void Client::setBalance(double bal) {
    balance = bal;
}

// Getters

int Client::getAccountNumber() const {
    return accountNumber;
}

string Client::getName() const {
    return name;
}

string Client::getPhone() const {
    return telephoneNumber;
}

string Client::getCountry() const {
    return country;
}

double Client::getBalance() const {
    return balance;
}

ostream& operator<<(ostream& out, Client& a) {
    out << fixed << setprecision(2)
        << "Account Number: " << a.getAccountNumber()
        << "\nName: " << a.getName()
        << "\nPhone: " << a.getPhone()
        << "\nCountry: " << a.getCountry()
        << "\nBalance: " << "$" << a.getBalance();

    return out;

}


istream& operator>>(istream& in, Client& a) {

    int an{0};
    double ba{0};
    string na;
    string tel;
    string cou;

    cout << "Account Number: ";
    in >> an;
    a.setAccountNumber(an);

    in.ignore(1, '\n');

    cout << "Name: ";
    getline(in, na);
    a.setName(na);

    cout << "Phone: ";
    in >> tel;
    a.setPhone(tel);

    cout << "Country: ";
    in >> cou;
    a.setCountry(cou);

    cout << "Balance: ";
    in >> ba;
    a.setBalance(ba);

    return in;

}


