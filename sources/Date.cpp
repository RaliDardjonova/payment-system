#include "../headers/Date.h"
#include<string>
#include<regex>

Date::Date(){
    dateTime = {0};
    setDay(1);
}

Date::Date(const Date& other){
    dateTime = {0};
    setDay(1);
    setDay(other.getDay());
    setMonth(other.getMonth());
    setYear(other.getYear());
}

/* constructs an instance of date from string in the type YYYY-MM-DD */
Date::Date(std::string date){
    dateTime = {0};
    setDay(1);
    std::regex rx("\\d{4}-\\d{2}-\\d{2}");
    bool isDate = std::regex_match(date, rx);

    if(isDate){
        setYear(std::stoi(date.substr(0,4)));
        setMonth(std::stoi(date.substr(5, 2)));
        setDay(std::stoi(date.substr(8, 2)));
    }
    else {
        dateTime = {0};
        setDay(1);
    }
}

Date::~Date(){}

int Date::getDay() const {
    return dateTime.tm_mday;
}

int Date::getMonth() const {
    return dateTime.tm_mon + 1;
}

int Date::getYear() const {
    return dateTime.tm_year + 1900;
}

std::string Date::toString()
{
    char formatedDate[11];
    snprintf(formatedDate, sizeof(formatedDate), "%04d-%02d-%02d", getYear(), getMonth(), getDay());
    return formatedDate;
}

void Date::setYear(int newYear)
{
    tm dateToCheck = {0};
    dateToCheck.tm_year = newYear - 1900;
    dateToCheck.tm_mon = dateTime.tm_mon;
    dateToCheck.tm_mday = dateTime.tm_mday;

    if(mktime(&dateToCheck) != -1 && (newYear >= 0))
    {
        dateTime.tm_year = newYear - 1900;
    }
}

void Date::setMonth(int newMonth)
{
    tm dateToCheck = {0};
    dateToCheck.tm_year = dateTime.tm_year;
    dateToCheck.tm_mon = newMonth - 1;
    dateToCheck.tm_mday = dateTime.tm_mday;
    if(mktime(&dateToCheck) != -1 && newMonth >= 1 && newMonth <= 12)
    {
        dateTime.tm_mon = newMonth - 1;
    }
}

void Date::setDay(int newDay)
{
    tm dateToCheck = {0};
    dateToCheck.tm_year = dateTime.tm_year;
    dateToCheck.tm_mon = dateTime.tm_mon;
    dateToCheck.tm_mday = newDay;
    if(mktime(&dateToCheck) != -1 && newDay >= 1 && newDay <= 31)
    {
        dateTime.tm_mday = newDay;
    }
}

Date Date::getCurrentDate(){
    Date currentDate = Date();
    time_t currentTime = time(0);
    tm now = *(localtime(&currentTime));
    currentDate.setDay(now.tm_mday);
    currentDate.setMonth(now.tm_mon + 1);
    currentDate.setYear(now.tm_year + 1900);

    return currentDate;
}
