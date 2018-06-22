#ifndef _IBAN_H
#define _IBAN_H
#include<string>
#include <boost/multiprecision/cpp_int.hpp>
#include "sql-controllers.h"

class IBAN {
public:
    IBAN();
    IBAN(std::string);
    IBAN(const IBAN&);
    ~IBAN();
    std::string getBIC() const;
    std::string getBankName() const;
    std::string getIBAN() const;
    void setIBAN(std::string);
    static bool isCorrect(std::string);
private:
    std::string iban;
    static boost::multiprecision::int128_t atoint128_t(std::string);
    static int getCorrespondingDigit(char);
    static std::string convertToDigits(std::string);
};

#endif //_IBAN_H
