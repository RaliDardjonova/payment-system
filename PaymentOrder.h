#ifndef _PAYMENTORDER_H
#define _PAYMENTORDER_H
#include<string>
#include "IBAN.h"
#include "MoneyOriginDeclaration.h"
#include "SettlementSystem.h"
#define CURRENCY_LENGTH 3

class PaymentOrder {
public:
    PaymentOrder();
    PaymentOrder(const PaymentOrder&);
    ~PaymentOrder();
    virtual void setReceiverIBAN(IBAN);
    void setReceiverName(std::string);
    void setDescription(std::string);
    void setSenderIBAN(IBAN);
    void setSenderName(std::string);
    void setSettlementSystem(SettlementSystem);
    void setAmount(double);

    IBAN getReceiverIBAN() const;
    std::string getReceiverName() const;
    std::string getDescription() const;
    IBAN getSenderIBAN() const;
    std::string getSenderName() const;
    SettlementSystem getSettllementSystem() const;
    double getAmount() const;

    virtual void save(bool) = 0;
    virtual std::string getCurrency() const = 0;
protected:
    IBAN receiverIBAN;
    std::string receiverName;
    std::string description;
    IBAN senderIBAN;
    std::string senderName;
    SettlementSystem settlementSystem;
    double amount;
    MoneyOriginDeclaration declaration;
};

#endif //_PAYMENTORDER_H
