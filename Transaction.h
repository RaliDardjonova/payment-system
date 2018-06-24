#ifndef _TRANSACTION_H
#define _TRANSACTION_H
#include "PaymentOrder.h"
#include "Date.h"
#include "transactionStatus.h"

class Transaction{
public:
    Transaction( PaymentOrder::OrderPointer);
    Transaction(const Transaction&);
    ~Transaction();
    void setPaymentOrder( PaymentOrder::OrderPointer);
    void setSignDate(Date);
    void setStatus(TransactionStatus);
    PaymentOrder::OrderPointer getPaymentOrder() const;
    Date getSignDate() const;
    TransactionStatus getStatus() const;

    void save();
    static std::string getOrderID(std::string);
    static void deleteFromDB(std::string);
private:
    PaymentOrder::OrderPointer order;
    Date signDate;
    TransactionStatus status;
};
#endif
