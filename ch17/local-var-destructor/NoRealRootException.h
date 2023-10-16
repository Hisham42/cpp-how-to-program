#ifndef NO_REAL_ROOT_EXCEPTION
#define NO_REAL_ROOT_EXCEPTION
#include <stdexcept>

class NoRealRootException : public std::runtime_error
{

public:
    NoRealRootException()
        : std::runtime_error{"No Real Root Exception"} {

        }
};

#endif