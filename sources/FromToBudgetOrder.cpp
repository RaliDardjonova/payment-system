#include "../headers/FromToBudgetOrder.h"

FromToBudgetOrder::FromToBudgetOrder(){
    document = Document();
    relevantPaymentPeriodStart = Date();
    relevantPaymentPeriodEnd = Date();
    paymentType = "0";
}

FromToBudgetOrder::FromToBudgetOrder(const FromToBudgetOrder& other){
    document = Document(other.getDocument());
    relevantPaymentPeriodStart = Date(other.getRelevantPaymentPeriodStart());
    relevantPaymentPeriodEnd = Date(other.getRelevantPaymentPeriodEnd());
    paymentType = other.getPaymentType();
}

FromToBudgetOrder::~FromToBudgetOrder(){}

PaymentOrder::OrderPointer FromToBudgetOrder::create () const {
    return OrderPointer(new FromToBudgetOrder());
}

PaymentOrder::OrderPointer FromToBudgetOrder::clone () const {
    return OrderPointer(new FromToBudgetOrder(*this));
}

std::string FromToBudgetOrder::currency = "BGN";

std::string FromToBudgetOrder::getCurrency() const {
    return currency;
}

void FromToBudgetOrder::setRelevantPaymentPeriodStart(Date newRelevantPaymentPeriodStart){
    relevantPaymentPeriodStart = Date(newRelevantPaymentPeriodStart);
}

void FromToBudgetOrder::setRelevantPaymentPeriodEnd(Date newRelevantPaymentPeriodEnd){
    relevantPaymentPeriodEnd = Date(newRelevantPaymentPeriodEnd);
}

void FromToBudgetOrder::setPaymentType(std::string newPaymentType){
    std::string IBANTypeIdentifier = getReceiverIBAN().getIBAN().substr(12,2);
    if(FromToBudgetOrder::isTypeCorrect(newPaymentType, IBANTypeIdentifier)){
        paymentType = newPaymentType;
    }
}

void FromToBudgetOrder::setReceiverIBAN(IBAN newIBAN){
    if(FromToBudgetOrder::isReceiverIBANCorrect(newIBAN.getIBAN())){
        receiverIBAN = newIBAN;
    }
}

void FromToBudgetOrder::setDocument(Document newDocument){
    document = Document(newDocument);
}

Date FromToBudgetOrder::getRelevantPaymentPeriodStart() const {
    return relevantPaymentPeriodStart;
}

Date FromToBudgetOrder::getRelevantPaymentPeriodEnd() const {
    return relevantPaymentPeriodEnd;
}

std::string FromToBudgetOrder::getPaymentType() const {
    return paymentType;
}

Document FromToBudgetOrder::getDocument() const {
    return document;
}

std::string FromToBudgetOrder::getAmountInWords() {
    double wholePart;
    double decimalPart = std::round(std::modf(getAmount(), &wholePart)*100);
    NumberInWords amountInWords = NumberInWords(wholePart, decimalPart);
    std::string fullAmountInwords = amountInWords.getWholePartInWords() + " leva";
    if(decimalPart != 0){
        fullAmountInwords += " and " + amountInWords.getDecimalPartInWords() + " stotinki";
    }
    return fullAmountInwords;
}

bool FromToBudgetOrder::isTypeCorrect(std::string IBANTypeIdentifier, std::string paymentTypetoCheck){
    std::string firstDigits = paymentTypetoCheck.substr(0,2);
    std::string expectedfirstDigits = paymentTypes.find(IBANTypeIdentifier)->second;
    return firstDigits == expectedfirstDigits;
}

bool FromToBudgetOrder::isReceiverIBANCorrect(std::string receiverIBANToCheck){
    std::string IBANTypeIdentifier = receiverIBANToCheck.substr(13, 2);
    return FromToBudgetOrder::paymentTypes.find(IBANTypeIdentifier) != paymentTypes.end();
}

/* save a from/to budget order into DB
with possibility of being template */
void FromToBudgetOrder::save(bool isTemplate){
    std::string paymentOrderValues = "NULL, 'B', '" + std::to_string(isTemplate) +
                                    "', '" + getSenderIBAN().getIBAN() +
                                    "', '" + getSenderName() + "'";
    saveToTable(paymentOrderValues, "PaymentOrder");

    std::string fromToBudgetOrderValues = "'" + getLastInsertedID() +
                                    "', '" + getReceiverIBAN().getIBAN() +
                                    "', '" + getReceiverName() +
                                    "', '" + std::to_string(getAmount()) +
                                    "', '" + getDescription() +
                                    "', '" + getRelevantPaymentPeriodStart().toString() +
                                    "', '" + getRelevantPaymentPeriodEnd().toString() +
                                    "', '" + getPaymentType() +
                                    "', '" + std::to_string(getSettllementSystem()) +
                                    "', '" + getDocument().getNumber() + "'";
    saveToTable(fromToBudgetOrderValues, "FromToBudgetOrder");
}

void FromToBudgetOrder::deleteFromDB(std::string orderID){
    PaymentOrder::deleteFromDB(orderID);
}

/* set of corresponding IBAN 13 and 14 symbol
to the two first symbols of payment type */
std::unordered_map<std::string, std::string> FromToBudgetOrder::paymentTypes = {
        {"81","11"},
        {"82","22"},
        {"83","33"},
        {"84","44"},
        {"85","55"},
        {"86","56"},
        {"87","57"},
        {"88","58"},
        {"89","59"}
};
