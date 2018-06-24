#include "OrdinaryOrder.h"

OrdinaryOrder::OrdinaryOrder(){}
OrdinaryOrder::OrdinaryOrder(const OrdinaryOrder& other){}
OrdinaryOrder::~OrdinaryOrder(){}

PaymentOrder::OrderPointer OrdinaryOrder::create () const {
    return OrderPointer(new OrdinaryOrder());
}

PaymentOrder::OrderPointer OrdinaryOrder::clone () const {
    return OrderPointer(new OrdinaryOrder(*this));
}

std::string OrdinaryOrder::currency = "BGN";

std::string OrdinaryOrder::getCurrency() const {
    return currency;
}

void OrdinaryOrder::save(bool isTemplate){
    std::string paymentOrderValues = "NULL, 'C', '" + std::to_string(isTemplate) +
                                    "', '" + getSenderIBAN().getIBAN() +
                                    "', '" + getSenderName() + "'";
    saveToTable(paymentOrderValues, "PaymentOrder");

    std::string ordinaryOrderValues = "'" + getLastInsertedID() +
                                    "', '" + getReceiverIBAN().getIBAN() +
                                    "', '" + getReceiverName() +
                                    "', '" + std::to_string(getAmount()) +
                                    "', '" + getDescription() +
                                    "', '" + std::to_string(getSettllementSystem()) + "'";
    saveToTable(ordinaryOrderValues, "OrdinaryOrder");
}

void OrdinaryOrder::deleteFromDB(std::string orderID){
    PaymentOrder::deleteFromDB(orderID);
}
