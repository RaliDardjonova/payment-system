#ifndef _DATE_H
#define _DATE_H
#include<ctime>
#include<string>

class Date{
public:
    Date();
    std::string getDate();
    time_t getTime();
    int getDay();
    int getMonth();
    int getYear();
    void setDay(unsigned int newDay);
    void setMonth(unsigned int newMonth);
    void setYear(unsigned int newDay);
private:
    tm *dateTime;
};


#endif


