// Fig. 9.19: Date.cpp
// Date class member-function definitions.

#include "Date.h" // include Date class definition




// constructor confirms proper value for month; calls
// utility function checkDay to confirm proper value for day
Date::Date(unsigned int mn, unsigned int dy, unsigned int yr)
   : month{mn}, day{checkDay(dy)}, year{yr} {
   if (mn < 1 || mn > monthsPerYear) { // validate the month
      throw invalid_argument("month must be 1-12");
   }

   // output Date object to show when its constructor is called
   cout << "Date object constructor for date " << toString() << endl;

}

Date::Date()
{
   time_t now = time(NULL);

   struct tm nowLocal = *localtime(&now);
   

   unsigned int dd =static_cast<unsigned int> (nowLocal.tm_mday);

   unsigned int mm =static_cast<unsigned int> (nowLocal.tm_mon) + 1;


   unsigned int yy =static_cast<unsigned int> (nowLocal.tm_year);


   month = mm;
   day = dd;
   year = yy - 100 + 2000;

}

// print Date object in form month/day/year
string Date::toString() const {
   ostringstream output;
   output << month << '/' << day << '/' << year;
   return output.str();
}

// print Date object in form DDD YYYY
string Date::toStringDDDYYYY() const {

   ostringstream output;
   output << calculateDDD(month, day) << ' ' << year;
   return output.str();
}

string Date::toStringMDY() const {

   ostringstream output;

   output << transformMonth(month) << " " << day << ", " << year;

   return output.str();
}

// output Date object to show when its destructor is called
Date::~Date() {
   cout << "Date object destructor for date " << toString() << endl;
}

// utility function to confirm proper day value based on 
// month and year; handles leap years, too
unsigned int Date::checkDay(int testDay) const {
   static const array<int, monthsPerYear + 1> daysPerMonth{
      0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

   // determine whether testDay is valid for specified month
   if (testDay > 0 && testDay <= daysPerMonth[month]) {
      return testDay;
   }

   // February 29 check for leap year 
   if (month == 2 && testDay == 29 && (year % 400 == 0 ||
      (year % 4 == 0 && year % 100 != 0))) {
      return testDay;
   }

   throw invalid_argument("Invalid day for current month and year");
}


unsigned int Date::calculateDDD(unsigned int m , unsigned int d) const
{
   int monthDays{0};

   static array<int, monthsPerYear + 1> daysPerMonth{
      0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

   
   if (m == 2 && d == 29 && (year % 400 == 0 ||
      (year % 4 == 0 && year % 100 != 0))) {
      daysPerMonth[2] = 29;
   }

   for (size_t i = 0; i < m; i++)
   {
      monthDays += daysPerMonth[i];
   }
   

   return (monthDays + d);

}

string Date::transformMonth(unsigned int m) const
{
   string arr[12] = {"Jan", "Feb", "Mar",
                     "Apr", "May", "June",
                     "July", "Aug", "Sep"
                     ,"Oct", "Nov", "Dec"};

   return arr[m-1];
}

