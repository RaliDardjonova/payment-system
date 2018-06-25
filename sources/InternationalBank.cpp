#include "../headers/InternationalBank.h"


InternationalBank::InternationalBank()
{
    bankSWIFT = "";
}

InternationalBank::InternationalBank(std::string newBankSWIFT)
{
    setBankSWIFT(newBankSWIFT);
}


std::string InternationalBank::getBankName() {
    sql::Statement *statement;
    sql::ResultSet *result;
    std::string bankName = "";
    std::string query = "select BankName from InternationalBank where bankSWIFT = '" + this->getBankSWIFT() + "';";

    try {
        statement = connection->createStatement();
        result = statement->executeQuery(query);

        if(result->next()){
            bankName = result->getString("bankName");
        }
    } catch (sql::SQLException &e) {
        printSQLError(e);
    }
    return bankName;
}


std::string InternationalBank::getBankAddress() {
    sql::Statement *statement;
    sql::ResultSet *result;
    std::string bankAddress = "";
    std::string query = "select BankAddress from InternationalBank where bankSWIFT = '" + this->getBankSWIFT() + "';";

    try {
        statement = connection->createStatement();
        result = statement->executeQuery(query);

        if(result->next()){
            bankAddress = result->getString("bankAddress");
        }
    } catch (sql::SQLException &e) {
        printSQLError(e);
    }
    return bankAddress;
}

std::string InternationalBank::getBankSWIFT() {
    return bankSWIFT;
}

void InternationalBank::setBankSWIFT(std::string newBankSWIFT){
    if(newBankSWIFT.size() == SWIFT_LENGTH){
        bankSWIFT = newBankSWIFT;
    }
}

void InternationalBank::save(){
    std::string values = "'" + getBankSWIFT() +
                        "', '" + getBankName() +
                        "', '" + getBankAddress() + "'";
    saveToTable(values, "InternationalBank");
}
