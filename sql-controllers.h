#ifndef _SQL_CONTROLLERS_H
#define _SQL_CONTROLLERS_H

#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

extern sql::Driver *driver;
extern sql::Connection *con;
extern sql::Statement *stmt;
extern sql::ResultSet *res;

void createConnection();



#endif // _SQL_CONTROLLERS_H
