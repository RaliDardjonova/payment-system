#include "PaymentOrder.h"

PaymentOrder::PaymentOrder(){
    receiverIBAN = IBAN();
    receiverName = "";
    description = "";
    senderIBAN = IBAN();
    senderName = "";
    settlementSystem = BORIKA;
    amount = 0;
}

PaymentOrder::PaymentOrder(const PaymentOrder& other){
    receiverIBAN = IBAN(other.getReceiverIBAN());
    receiverName = other.getReceiverName();
    description = other.getDescription();
    senderIBAN = IBAN(other.getSenderIBAN());
    senderName = other.getSenderName();
    settlementSystem = other.getSettllementSystem();
    amount = other.getAmount();
}

PaymentOrder::~PaymentOrder(){}


void PaymentOrder::setReceiverIBAN(IBAN newIBAN){
    receiverIBAN = IBAN(newIBAN);
}

void PaymentOrder::setReceiverName(std::string newName){
    receiverName = newName;
}

void PaymentOrder::setDescription(std::string newDescription){
    description = newDescription;
}

void PaymentOrder::setSenderIBAN(IBAN newIBAN){
    senderIBAN = IBAN(newIBAN);
}

void PaymentOrder::setSenderName(std::string newName){
    senderName = newName;
}

void PaymentOrder::setSettlementSystem(SettlementSystem newSetllementSystem){
    settlementSystem = newSetllementSystem;
}

void PaymentOrder::setAmount(double newAmount){
    if(newAmount >= 0){
        amount = newAmount;
    }
}

IBAN PaymentOrder::getReceiverIBAN() const {
    return receiverIBAN;
}

std::string PaymentOrder::getReceiverName() const {
    return receiverName;
}

std::string PaymentOrder::getDescription() const {
    return description;
}

IBAN PaymentOrder::getSenderIBAN() const {
    return senderIBAN;
}

std::string PaymentOrder::getSenderName() const {
    return senderName;
}

SettlementSystem PaymentOrder::getSettllementSystem() const {
    return settlementSystem;
}

double PaymentOrder::getAmount() const {
    return amount;
}
