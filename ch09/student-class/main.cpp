#include <iostream>
#include "student.h"

using namespace std;

int main()
{

    Date yearOfBirth(3,3,1989);


   
    Name nAhmed("s", "Mohamed", "Mousa");



    Student A(nAhmed, "male", yearOfBirth, 65487, "ahmed@gmail.com");


    A.getStudentName();

    A.getDate();
 





}