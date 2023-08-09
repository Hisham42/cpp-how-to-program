#include <string>

#ifndef NAME_H
#define NAME_H

class Name
{
private:
    /* data */
    std::string firstName, middleName, LastName, salutation;
public:
    Name(std::string first, std::string second, std::string third, std::string salut);
    ~Name();

    std::string toString();

    void setFirst(std::string fir);

    void setMiddle(std::string sec);

    void setLast(std::string thir);

    void setSalut(std::string sal);

    std::string getFirst();
    std::string getMiddle();
    std::string getLast();
    std::string getSalut();

};



#endif