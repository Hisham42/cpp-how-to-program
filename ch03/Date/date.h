#include <string>
#include <iostream>

class Date
{
private:
    /* data */
    int month;
    int day;
    int year;

public:

    // constructor
    Date(int inMonth, int inDay, int inYear) : month{inMonth}, day{inDay}, year{inYear} {
        if (month < 1 || month > 12)
        {
            month = 1;
        }
        
    }

    void setMonth(int dMonth)
    {
        month = dMonth;
    }

    void setDay(int dDay)
    {
        day = dDay;
    }

    void setYear(int dYear)
    {
        year = dYear;
    }

    int getMonth()
    {
        return month;
    }

    int getDay()
    {
        return day;
    }

    int getYear()
    {
        return year;
    }


    void displayDate() {

        std::cout << "Date: " << month << "/" << day << "/" << year << std::endl;
    
    }
};
