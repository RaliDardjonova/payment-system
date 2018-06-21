#ifndef _INTERNATIONALPAYMENTORDER_H
#define _INTERNATIONALPAYMENTORDER_H

#include "PaymentOrder.h"
#include "InternationalBank.h"
#include "ValueDate.h"
#include "ChargesDetails.h"

class InternationalPaymentOrder: public PaymentOrder {
public:

std::string getOperationName();
double computeSenderCharges();
double computerReceiverCharges();

private:
    std::string currency;
    std::string receiverAddress;
    std::string receiverCountrey;
    InternationalBank receiverBank;
    InternationalBank otherBank;
    std::string operationCode;
    ValueDate executionPeriod;
    ChargesDetails senderCharges;
    ChargesDetails receiverCharges;
};

#endif //_INTERNATIONALPAYMENTORDER_H
