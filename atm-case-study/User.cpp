#include "User.h"

User::~User()
{
    // unauthenticate user
    status = false;
}

// check if user authenticated or not
bool User::getStatus() const
{
    return status;
}

// authenticate or unauthenticate user
void User::setStatus(bool state)
{
    status = state;
}
