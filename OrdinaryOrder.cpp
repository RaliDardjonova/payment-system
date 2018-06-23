#include "OrdinaryOrder.h"

OrdinaryOrder::OrdinaryOrder(){}
OrdinaryOrder::OrdinaryOrder(const OrdinaryOrder& other){}
OrdinaryOrder::~OrdinaryOrder(){}

std::string OrdinaryOrder::currency = "BGN";

std::string OrdinaryOrder::getCurrency() const {
    return currency;
}

void OrdinaryOrder::save(bool isTemplate){
    std::string paymentOrderValues = "NULL, 'C', '" + std::to_string(isTemplate) + "'";
    saveToTable(paymentOrderValues, "PaymentOrder");

    std::string ordinaryOrderValues = "'" + std::to_string(getLastInsertedID()) +
                                    "', '" + getReceiverIBAN().getIBAN() +
                                    "', '" + getReceiverName() +
                                    "', '" + std::to_string(getAmount()) +
                                    "', '" + getDescription() +
                                    "', '" + std::to_string(getSettllementSystem()) + "'";
    saveToTable(ordinaryOrderValues, "OrdinaryOrder");
}
