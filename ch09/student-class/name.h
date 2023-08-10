#include <string>

#ifndef NAME_H
#define NAME_H

class Name
{
private:
    /* data */
    std::string firstName, middleName, LastName;
public:
    Name(std::string first, std::string second, std::string third);
    ~Name();

    std::string toString();

    void setFirst(std::string fir);

    void setMiddle(std::string sec);

    void setLast(std::string thir);

    

    std::string getFirst();
    std::string getMiddle();
    std::string getLast();
    

};



#endif