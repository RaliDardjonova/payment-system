#include "IBAN.h"

IBAN::IBAN(){
    iban = "";
}

IBAN::IBAN(std::string newIBAN){
    setIBAN(newIBAN);
}

IBAN::IBAN(const IBAN& other){
    setIBAN(other.getIBAN());
}

IBAN::~IBAN(){}

std::string IBAN::getIBAN() const {
    return iban;
}

std::string IBAN::getBIC() const {

    std::string shortName = getIBAN().substr(4, 4);
    sql::Statement *statement;
    sql::ResultSet *result;
    std::string query = "select BIC from Bank where shortName = '" + shortName + "';";

    try {
        statement = connection->createStatement();
        result = statement->executeQuery(query);
        if(result->next())
        {
            return result->getString("BIC");
        }
    } catch (sql::SQLException &e) {
        printSQLError(e);
    }
    return "";
}


std::string IBAN::getBankName() const {
    std::string shortName = getIBAN().substr(4, 4);
    sql::Statement *statement;
    sql::ResultSet *result;
    std::string query = "select name from Bank where shortName = '" + shortName + "';";

    try {
        statement = connection->createStatement();
        result = statement->executeQuery(query);
        if(result->next())
        {
            return result->getString("name");
        }
    } catch (sql::SQLException &e) {
        printSQLError(e);
    }
    return "";
}

void IBAN::setIBAN(std::string newIBAN){
    if(IBAN::isCorrect(newIBAN)){
        iban = newIBAN;
    }
}

bool IBAN::isCorrect(std::string candidateIBAN) {
    if(candidateIBAN.size() != 22){
        return false;
    }
    std::string firstPart = candidateIBAN.substr(0,4);
    std::string secondPart = candidateIBAN.substr(4);
    std::string convertedIBAN = IBAN::convertToDigits(secondPart) + IBAN::convertToDigits(firstPart);

    boost::multiprecision::int128_t numericIBAN = IBAN::atoint128_t(convertedIBAN);
    boost::multiprecision::int128_t remainder = numericIBAN % 97;

    return remainder == 1;
}

int IBAN::getCorrespondingDigit(char letter){
    if(letter >= 'A' && letter <= 'Z'){
        return (int)letter - 55;
    }
    return -1;
}

std::string IBAN::convertToDigits(std::string letters){
    std::string digits;
    int lettersLength = letters.size();

    for(int i = 0; i < lettersLength; i++){
        if(letters[i] >= '0' && letters[i] <= '9'){
            digits += letters[i];
        }
        else {
            digits += std::to_string(IBAN::getCorrespondingDigit(letters[i]));
        }
    }
    return digits;
}

boost::multiprecision::int128_t IBAN::atoint128_t(std::string str)
{
    boost::multiprecision::int128_t result = 0;

    for (size_t i = 0; i < str.size(); ++i)
    {
        const char c = str[i];
        result *= 10;
        result += c - '0';
    }

    return result;
}
