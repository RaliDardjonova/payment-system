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
    void setDay(int newDay);
    void setMonth(int newMonth);
    void setYear(int newDay);
    static Date getCurrentDate();
private:
    tm dateTime;
};

#endif
