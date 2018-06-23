#ifndef _FROMTOBUDGETORDER_H
#define _FROMTOBUDGETORDER_H

#include <string>
#include <unordered_map>
#include <math.h>
#include "PaymentOrder.h"
#include "Document.h"
#include "NumberInWords.h"
#include "sql-controllers.h"

class FromToBudgetOrder: public PaymentOrder {
public:
    FromToBudgetOrder();
    FromToBudgetOrder(const FromToBudgetOrder &other);
    ~FromToBudgetOrder();

    void setRelevantPaymentPeriodStart(Date);
    void setRelevantPaymentPeriodEnd(Date);
    void setPaymentType(std::string);
    void setDocument(Document);
    void setReceiverIBAN(IBAN);

    Date getRelevantPaymentPeriodStart() const;
    Date getRelevantPaymentPeriodEnd() const;
    std::string getPaymentType() const;
    std::string getAmountInWords();
    Document getDocument() const;
    std::string getCurrency() const;
    void save(bool);
private:
    static std::string currency;
    Date relevantPaymentPeriodStart;
    Date relevantPaymentPeriodEnd;
    std::string paymentType;
    Document document;
    static bool isTypeCorrect(std::string, std::string);
    static bool isReceiverIBANCorrect(std::string);
    static std::unordered_map<std::string, std::string> paymentTypes;
};

#endif //_FROMTOBUDGETORDER_H
