#include "Person.h"
#include <cstring>

Person::Person(const std::string& newLastName, const std::string& newFirstName, int newId, int newAge)
    
{
    // Ensure that the lastName does not exceed the maximum length
    setLastName(newLastName);
    setFirstName(newFirstName);
    setId(newId);
    setAge(newAge);
}

// Destructor
Person::~Person() {
    // Destructor code, if needed
}





// accessor functions for id
void Person::setId(int newId) {
    id = newId;
}

int Person::getId() const {
    return id;
}

// accessor functions for lastName
void Person::setLastName(const std::string& newLastName) {
    // Ensure that the lastName does not exceed the maximum length
    int length = newLastName.length() < 15 ? newLastName.length() : 14;
    strncpy(lastName, newLastName.c_str(), length);
    lastName[length] = '\0'; // Ensure null-termination
}

std::string Person::getLastName() const {
    return std::string(lastName);
}

// accessor functions for firstName
void Person::setFirstName(const std::string& newFirstName) {
    // Ensure that the firstName does not exceed the maximum length
    int length = newFirstName.length() < 10 ? newFirstName.length() : 9;
    strncpy(firstName, newFirstName.c_str(), length);
    firstName[length] = '\0'; // Ensure null-termination
}

std::string Person::getFirstName() const {
    return std::string(firstName);
}

// accessor functions for age
void Person::setAge(int newAge) {
    age = newAge;
}

int Person::getAge() const {
    return age;
}
