#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Person
{

private:
    char lastName[15];
    char firstName[10];
    int age;
    int id;
    

public:
    Person(const string& = "", const string& ="", int=0, int=0);
    ~Person();

    // setters

    // accessor functions for id
    void setId(int);
    int getId() const;
    // accessor functions for lastName
    void setLastName(const string&);
    string getLastName() const;
    // accessor functions for firstName
    void setFirstName(const string&);
    string getFirstName() const;
    // accessor functions for age
    void setAge(int);
    int getAge() const;

};

#endif