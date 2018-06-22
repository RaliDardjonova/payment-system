#ifndef _DATE_H
#define _DATE_H
#include<ctime>
#include<string>

class Date{
public:
    Date();
    Date(const Date&);
    Date(std::string);
    ~Date();
    std::string toString();
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    void setDay(unsigned int newDay);
    void setMonth(unsigned int newMonth);
    void setYear(unsigned int newDay);
private:
    tm dateTime;
};

#endif


