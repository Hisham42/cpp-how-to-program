#include "User.h"

User::User(/* args */)
{
}

User::~User()
{
    status = false;
}

bool User::getStatus(/* args */) const
{
    return status;
}

void User::setStatus(bool state)
{
    status = state;
}
