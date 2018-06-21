#ifndef _INTERNATIONALBANK_H
#define _INTERNATIONALBANK_H
#include<string>

class InternationalBank {
public:
    std::string getBankName();
    std::string getBankAddress();
private:
    std::string bankSWIFT;
};

#endif //_INTERNATIONALBANK_H
