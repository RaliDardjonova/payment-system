#include "../headers/Transaction.h"

Transaction::Transaction(PaymentOrder::OrderPointer other) : order(other){
    signDate = Date();
    status = InProgress;
}

Transaction::Transaction(const Transaction& other){
    order = other.getPaymentOrder()->clone();
    signDate = Date(other.getSignDate());
    status = other.getStatus();
}

Transaction::~Transaction(){}

void Transaction::setPaymentOrder(PaymentOrder::OrderPointer newOrder){
    order = newOrder->clone();
}

void Transaction::setSignDate(Date newDate){
    signDate = newDate;
}

void Transaction::setStatus(TransactionStatus newStatus){
    status = newStatus;
}

 PaymentOrder::OrderPointer Transaction::getPaymentOrder() const {
    return order->clone();
}

Date Transaction::getSignDate() const {
    return signDate;
}

TransactionStatus Transaction::getStatus() const {
    return status;
}

void Transaction::save(){
    getPaymentOrder()->save(false);
    std::string values = "NULL, '" + getLastInsertedID() +
                        "', '" + getSignDate().toString() +
                        "', '" + std::to_string(getStatus()) + "'";
    saveToTable(values, "Transaction");
}

/* retreive the order id corresponding to
transaction id from the DB */
std::string Transaction::getOrderID(std::string transactionID){
    sql::Statement *statement;
    sql::ResultSet *result;
    std::string query = "select order_id from Transaction where trans_id = '" + transactionID + "';";

    try {
        statement = connection->createStatement();
        result = statement->executeQuery(query);
        if(result->next())
        {
            return result->getString("order_id");
        }
        return "";
        statement->execute(query);
    } catch (sql::SQLException &e) {
        printSQLError(e);
    }
    return "";
}

/* delete transaction from the DB
and its corresponding order */
void Transaction::deleteFromDB(std::string transactionID){
    PaymentOrder::deleteFromDB(getOrderID(transactionID));
}
