#ifndef _INTERNATIONALPAYMENTORDER_H
#define _INTERNATIONALPAYMENTORDER_H

#include <algorithm>
#include "PaymentOrder.h"
#include "InternationalBank.h"
#include "ValueDate.h"
#include "ChargesDetails.h"
#define MIN_SEND_CHARGE 15.0
#define MAX_SEND_CHARGE 200.0
#define MAX_RECEIVE_CHARGE 90.0

class InternationalOrder: public PaymentOrder {
public:
    InternationalOrder();
    InternationalOrder(const InternationalOrder&);
    ~InternationalOrder();
    OrderPointer create() const;
    OrderPointer clone() const;

    void setCurrency(std::string);
    void setReceiverAddress(std::string);
    void setReceiverCountry(std::string);
    void setReceiverBank(InternationalBank);
    void setIntermediaryBank(InternationalBank);
    void setExecutionPeriod(ValueDate);
    void setSenderCharges(ChargesDetails);
    void setReceiverCharges(ChargesDetails);

    std::string getCurrency() const;
    std::string getReceiverAddress() const;
    std::string getReceiverCountry() const;
    InternationalBank getReceiverBank() const;
    InternationalBank getIntermediaryBank() const;
    ValueDate getExecutionPeriod() const;
    ChargesDetails getSenderCharges() const;
    ChargesDetails getReceiverCharges() const;

    void save(bool);
    static void deleteFromDB(std::string);
    double computeOURCharges();
private:
    std::string currency;
    std::string receiverAddress;
    std::string receiverCountry;
    InternationalBank receiverBank;
    InternationalBank intermediaryBank;
    ValueDate executionPeriod;
    ChargesDetails senderCharges;
    ChargesDetails receiverCharges;
    double computeSenderCharges();
    double computeReceiverCharges();
    double persentageCharges();
};

#endif //_INTERNATIONALPAYMENTORDER_H
