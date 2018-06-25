#ifndef _INTERNATIONALBANK_H
#define _INTERNATIONALBANK_H
#include<string>
#include "sql-controllers.h"
#define SWIFT_LENGTH 8

class InternationalBank {
public:
    InternationalBank();
    InternationalBank(std::string bankSWIFT);
    std::string getBankName();
    std::string getBankAddress();
    std::string getBankSWIFT();
    void setBankSWIFT(std::string bankSWIFT);
    void save();
private:
    std::string bankSWIFT;
};

#endif //_INTERNATIONALBANK_H
