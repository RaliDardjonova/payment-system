#ifndef _MONEYORIGINDECLARATION_H
#define _MONEYORIGINDECLARATION_H
#include "Date.h"

class MoneyOriginDeclaration {
private:
    std::string declaratorName;
    std::string personalID;
    std::string nationality;
    std::string address;
    std::string IDnumber;
    Date IDissueDate;
    std::string position;
    std::string holderName;
    std::string holderAddress;
    std::string uniformID;
    std::string operationType;
    Date operationDate;
    double amount;
    std::string currency;
    std::string moneyOrigin;
};

#endif //_MONEYORIGINDECLARATION_H
