#include "Document.h"

Document::Document(){
    number = "";
    type = 0;
    date = Date();
    debitedParty = "";
}

Document::Document(const Document& other){
    type = other.getType();
    number = other.getNumber();
    date = Date (other.getDate());
    debitedParty = other.getDebitedParty();
}

Document::Document(std::string newNumber){
    sql::Statement *statement;
    sql::ResultSet *result;
    Document newDocument = Document();
    std::string query = "select * from Document where documentNumber = '" + newNumber + "';";

    try {
        statement = connection->createStatement();
        result = statement->executeQuery(query);

        if(result->next()){
            newDocument.setType(std::stoi(result->getString("documentType")));
            newDocument.setDate(Date(result->getString("documentDate")));
            newDocument.setDebitedParty(result->getString("debitedParty"));
            newDocument.setNumber(newNumber);
        }
    } catch (sql::SQLException &e) {
        printSQLError(e);
    }

    *this = Document(newDocument);
}

Document::~Document(){}

int Document::getType() const {
    return type;
}

std::string Document::getNumber() const {
    return number;
}

Date Document::getDate() const {
    return date;
}

std::string Document::getDebitedParty() const {
    return debitedParty;
}

void Document::setType(int newType){
    if(newType >= 0 && newType <= 9){
        type = newType;
    }
}

void Document::setNumber(std::string newNumber){
    number = newNumber;
}

void Document::setDate(Date newDate){
    date = newDate;
}

void Document::setDebitedParty(std::string newDebitedParty){
    debitedParty = newDebitedParty;
}

int Document::save(){
    sql::Statement *statement;
    sql::ResultSet *checkResult;
    std::string values =
                        "'" +
                        number +
                        "','" +
                        std::to_string(type) +
                        "','" +
                        date.toString() +
                        "','" +
                        debitedParty +
                        "'";
    std::string checkQuery = "select * from Document where documentNumber = '" + number + "';";
    std::string query = "insert into Document values (" + values + ")";

    try {
        statement = connection->createStatement();
        checkResult = statement->executeQuery(checkQuery);
        if(checkResult->next())
        {
            return -1;
        }
        statement->execute(query);
    } catch (sql::SQLException &e) {
        printSQLError(e);
    }
    return 0;
}
