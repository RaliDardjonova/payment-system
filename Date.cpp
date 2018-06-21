#include "Date.h"
#include<string>

Date::Date()
{
    time_t now = time(0);
    dateTime = localtime(&now);
    //year = 1900 + dateTime->tm_year;
    //month = 1 + dateTime->tm_mon;
   // day = dateTime ->tm_mday;
}


std::string Date::getDate()
{

}

void Date::setYear(unsigned int newYear)
{
    tm *dateToCheck;
    dateToCheck->tm_year = newYear;
    dateToCheck->tm_mon = dateTime->tm_mon;
    dateToCheck->tm_mday = dateTime->tm_mday;
    if(mktime(dateToCheck) != -1)
    {
        dateTime->tm_year = newYear;
    }
}

void Date::setMonth(unsigned int newMonth)
{
    tm *dateToCheck;
    dateToCheck->tm_year = dateTime->tm_year;
    dateToCheck->tm_mon = newMonth;
    dateToCheck->tm_mday = dateTime->tm_mday;
    if(mktime(dateToCheck) != -1)
    {
        dateTime->tm_mon = newMonth;
    }
}

void Date::setDay(unsigned int newDay)
{
    tm *dateToCheck;
    dateToCheck->tm_year = dateTime->tm_year;
    dateToCheck->tm_mon = dateTime->tm_mon;
    dateToCheck->tm_mday = newDay;
    if(mktime(dateToCheck) != -1)
    {
        dateTime->tm_mday = newDay;
    }
}
