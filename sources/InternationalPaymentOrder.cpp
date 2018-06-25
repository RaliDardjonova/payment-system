#include "../headers/InternationalPaymentOrder.h"

InternationalOrder::InternationalOrder(){
    currency = "EUR";
    receiverAddress = "";
    receiverCountry = "";
    receiverBank = InternationalBank();
    intermediaryBank = InternationalBank();
    executionPeriod = NORMAL;
    senderCharges = OUR;
    receiverCharges = OUR;
}

InternationalOrder::InternationalOrder(const InternationalOrder& other){
    setCurrency(other.getCurrency());
    setReceiverAddress(other.getReceiverAddress());
    setReceiverCountry(other.getReceiverCountry());
    setReceiverBank(other.getReceiverBank());
    setIntermediaryBank(other.getIntermediaryBank());
    setExecutionPeriod(other.getExecutionPeriod());
    setSenderCharges(other.getSenderCharges());
    setReceiverCharges(other.getReceiverCharges());
}

InternationalOrder::~InternationalOrder(){}

PaymentOrder::OrderPointer InternationalOrder::create () const {
    return OrderPointer(new InternationalOrder());
}

PaymentOrder::OrderPointer InternationalOrder::clone () const {
    return OrderPointer(new InternationalOrder(*this));
}

void InternationalOrder::setCurrency(std::string newCurrency){
    if(newCurrency.size() == CURRENCY_LENGTH){
        std::transform(newCurrency.begin(), newCurrency.end(), newCurrency.begin(), ::toupper);
        currency = newCurrency;
    }
}

void InternationalOrder::setReceiverAddress(std::string newReceiverAddress){
    receiverAddress = newReceiverAddress;
}

void InternationalOrder::setReceiverCountry(std::string newReceiverCountry){
    receiverCountry = newReceiverCountry;
}

void InternationalOrder::setReceiverBank(InternationalBank newReceiverBank){
    receiverBank = InternationalBank(newReceiverBank);
}

void InternationalOrder::setIntermediaryBank(InternationalBank newIntermediaryBank){
    intermediaryBank = InternationalBank(newIntermediaryBank);
}


void InternationalOrder::setExecutionPeriod(ValueDate newExecutionPeriod){
    executionPeriod = newExecutionPeriod;
}

void InternationalOrder::setSenderCharges(ChargesDetails newSenderCharges){
    senderCharges = newSenderCharges;
}

void InternationalOrder::setReceiverCharges(ChargesDetails newReceiverCharges){
    receiverCharges = newReceiverCharges;
}

std::string InternationalOrder::getCurrency() const{
    return currency;
}
std::string InternationalOrder::getReceiverAddress() const{
    return receiverAddress;
}

std::string InternationalOrder::getReceiverCountry() const{
    return receiverCountry;
}

InternationalBank InternationalOrder::getReceiverBank() const{
    return receiverBank;
}

InternationalBank InternationalOrder::getIntermediaryBank() const{
    return intermediaryBank;
}

ValueDate InternationalOrder::getExecutionPeriod() const{
    return executionPeriod;
}

ChargesDetails InternationalOrder::getSenderCharges() const{
    return senderCharges;
}

ChargesDetails InternationalOrder::getReceiverCharges() const{
    return receiverCharges;
}

/* save international order in the DB with
the possibility of being template */
void InternationalOrder::save(bool isTemplate){
    std::string paymentOrderValues = "NULL, 'I', '" + std::to_string(isTemplate) +
                                    "', '" + getSenderIBAN().getIBAN() +
                                    "', '" + getSenderName() + "'";
    saveToTable(paymentOrderValues, "PaymentOrder");

    std::string ordinaryOrderValues = "'" + getLastInsertedID() +
                                    "', '" + getReceiverIBAN().getIBAN() +
                                    "', '" + getReceiverName() +
                                    "', '" + getCurrency() +
                                    "', '" + std::to_string(getAmount()) +
                                    "', '" + getDescription() +
                                    "', '" + getReceiverAddress() +
                                    "', '" + getReceiverCountry() +
                                    "', '" + std::to_string(getExecutionPeriod()) +
                                    "', '" + std::to_string(getSenderCharges()) +
                                    "', '" + std::to_string(getReceiverCharges()) +
                                    "', '" + getReceiverBank().getBankSWIFT() +
                                    "', '" + getIntermediaryBank().getBankSWIFT() + "'";
    saveToTable(ordinaryOrderValues, "InternationalOrder");
}

double InternationalOrder::computeSenderCharges() {
   if(senderCharges == OUR){
        return std::min(std::max(getAmount()*persentageCharges(), MIN_SEND_CHARGE), MAX_SEND_CHARGE) + 9;
   }
   else {
        return 0;
   }
}

double InternationalOrder::computeReceiverCharges() {
    if(receiverCharges == OUR){
        return std::min(getAmount()*0.1 + 6, MAX_RECEIVE_CHARGE) ;
   }
   else {
        return 0;
   }
}

double InternationalOrder::computeOURCharges(){
    return computeSenderCharges() + computeReceiverCharges();
}

double InternationalOrder::persentageCharges(){
    switch(executionPeriod){
        case EXPRESS: return 0.4;
        case FAST: return 0.3;
        case NORMAL: return 0.2;
    }
    return 0;
}

void InternationalOrder::deleteFromDB(std::string orderID){
    PaymentOrder::deleteFromDB(orderID);
}
