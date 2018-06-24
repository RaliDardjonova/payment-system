//#define CATCH_CONFIG_MAIN

#include <iostream>
#include "sql-controllers.h"
#include "InternationalBank.h"

using namespace std;

/*
int main(int argc, char *argv[])
{
    cout << "Hello world!" << endl;


    try {

    createConnection();

    InternationalBank b = InternationalBank("12345678");
    cout<<b.getBankName()<<endl;
    cout<<b.getBankAddress()<<endl;


  sql::Statement *stmt;
    sql::ResultSet *res;

  stmt = connection->createStatement();
  res = stmt->executeQuery("select * from InternationalBank;"); // replace with your statement
  while (res->next()) {
    cout << "\t... MySQL replies: ";

    cout << res->getString("bankName") << endl;
    cout << "\t... MySQL says it again: ";

    cout << res->getString(1) << endl;
  }
  delete res;
  delete stmt;


  } catch (sql::SQLException &e) {
  //cout << "# ERR: SQLException in " << __FILE__;
  //cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
  //cout << "# ERR: " << e.what();
  //cout << " (MySQL error code: " << e.getErrorCode();
  //cout << ", SQLState: " << e.getSQLState() << " )" << endl;

}

    return 0;
}
*/
