#ifndef _PAYMENTORDER_H
#define _PAYMENTORDER_H
#include<string>
#include<memory>
#include "IBAN.h"
#include "SettlementSystem.h"
#define CURRENCY_LENGTH 3


class PaymentOrder {
public:
    typedef std::shared_ptr<PaymentOrder> OrderPointer;
    PaymentOrder();
    PaymentOrder(const PaymentOrder&);
    virtual ~PaymentOrder();
    virtual OrderPointer create () const = 0;
    virtual OrderPointer clone () const = 0;

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
    static void deleteFromDB(std::string);
protected:
    IBAN receiverIBAN;
    std::string receiverName;
    std::string description;
    IBAN senderIBAN;
    std::string senderName;
    SettlementSystem settlementSystem;
    double amount;
};

#endif //_PAYMENTORDER_H
