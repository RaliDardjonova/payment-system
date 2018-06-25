#include<iostream>
#include "../headers/sql-controllers.h"

sql::Driver *driver;
sql::Connection *connection;

void createConnection(){
    try {
        driver = get_driver_instance();
        connection = driver->connect("tcp://127.0.0.1:3306", "ralitsa", "");
        connection->setSchema("PaymentSystem");

    } catch (sql::SQLException &e) {
        printSQLError(e);
        exit(1);
    }
}

void printSQLError(sql::SQLException &e){
    std::cout << "# ERR: SQLException in " << __FILE__;
    std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
    std::cout << "# ERR: " << e.what();
    std::cout << " (MySQL error code: " << e.getErrorCode();
    std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
}

void saveToTable(std::string values, std::string table){
    sql::Statement *statement;
    std::string query = "insert into " + table + " values (" + values + ")";

    try {
        statement = connection->createStatement();
        statement->execute(query);
    } catch (sql::SQLException &e) {
        printSQLError(e);
    }
}

std::string getLastInsertedID(){
    sql::Statement *statement;
    sql::ResultSet *result;
    std::string query = "SELECT LAST_INSERT_ID();";

    try {
        statement = connection->createStatement();
        result = statement->executeQuery(query);
        if(result->next()){
            return result->getString("LAST_INSERT_ID()");
        }
    } catch (sql::SQLException &e) {
        printSQLError(e);
    }
    return 0;
}

void deleteFromTable(std::string condition, std::string table){
    try{
        sql::Statement *statement = connection->createStatement();
        statement->execute("delete from " + table + " where " + condition + ";");
    } catch (sql::SQLException &e) {
        printSQLError(e);
    }
}
