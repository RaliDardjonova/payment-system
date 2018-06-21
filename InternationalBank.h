#ifndef _INTERNATIONALBANK_H
#define _INTERNATIONALBANK_H
#include<string>
#include "sql-controllers.h"

class InternationalBank {
public:
    InternationalBank();
    InternationalBank(std::string bankSWIFT);
    std::string getBankName();
    std::string getBankAddress();
    std::string getBankSWIFT();
    void setBankSWIFT(std::string bankSWIFT);
private:
    std::string bankSWIFT;
};

#endif //_INTERNATIONALBANK_H
