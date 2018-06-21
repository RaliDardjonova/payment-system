#include "sql-controllers.h"

sql::Driver *driver;
sql::Connection *con;
sql::Statement *stmt;
sql::ResultSet *res;

void createConnection()
{
    driver = get_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306", "ralitsa", "");
    con->setSchema("PaymentSystem");
}
