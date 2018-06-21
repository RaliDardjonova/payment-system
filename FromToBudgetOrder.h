/**
 * Project ST
 */


#ifndef _FROMTOBUDGETORDER_H
#define _FROMTOBUDGETORDER_H

#include "PaymentOrder.h"
#include <string>

class FromToBudgetOrder: public PaymentOrder {
public:
    std::string getAmountInWords();
private:
    static std::string currency;
    int documentType;
    int documentNumber;
    Date documentDate;
    Date relevantPaymentPeriodStart;
    Date relevantPaymentPeriodEnd;
    std::string paymentType;
    std::string debitedParty;
};

#endif //_FROMTOBUDGETORDER_H
