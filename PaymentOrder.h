#ifndef _PAYMENTORDER_H
#define _PAYMENTORDER_H
#include "IBAN.h"
#include<string>
#include "MoneyOriginDeclaration.h"
class PaymentOrder {
public:

void createTemplate();

bool checkOrderFields();
protected:
    IBAN receiverIBAN;
    std::string receiverName;
    std::string description;
    std::string senderName;
    IBAN senderIBAN;
    std::string paymentSystem;
    double amount;
    MoneyOriginDeclaration declaration;
};

#endif //_PAYMENTORDER_H
