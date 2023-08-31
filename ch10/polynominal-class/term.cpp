#include "term.h"

Term::Term(const int& c, const int& e)

{
    coefficient = c;
    exponenet = e;

}

Term::Term(const Term* t)
: coefficient(t->coefficient), exponenet(t->exponenet)
{
}

Term::Term()
{

}


Term::~Term()
{

}

int Term::getC()
{
    return coefficient;
}

int Term::getE()
{
    return exponenet;
}

bool Term::getStatus()
{
    return checked;
}

void Term::setStatus(bool a)
{
    checked = a;
}

void Term::setC(int a)
{
    coefficient = a;
}

void Term::setE(int a)
{
    exponenet = a;
}


bool Term::isIn(Poly& a)
{
    for (int i = 0; i < a.getSize(); i++)
    {
        if (exponenet == a.getPtr(i).getE())
        {
            return false;
        }

        if (i == a.getSize() - 1)
        {
            break;
        } 
    }
    return true;
}