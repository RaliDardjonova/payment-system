#ifndef _SQL_CONTROLLERS_H
#define _SQL_CONTROLLERS_H

#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

extern sql::Driver *driver;
extern sql::Connection *connection;


void createConnection();
void printSQLError(sql::SQLException &e);
void saveToTable(std::string, std::string);
std::string getLastInsertedID();
void deleteFromTable(std::string, std::string);

#endif // _SQL_CONTROLLERS_H
