#ifndef User_H
#define User_H

class User
{
private:
    bool status {false};

public:
    ~User();

    bool getStatus() const;
    void setStatus(bool state);


};



#endif