#ifndef _IBAN_H
#define _IBAN_H
#include<string>

class IBAN {
public:
    std::string getBIC();
    std::string getBankName();
    bool checkIBANCorrectness();
private:
    std::string IBAN[22];
};

#endif //_IBAN_H
