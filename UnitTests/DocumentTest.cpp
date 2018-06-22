#include "catch.hpp"
#include "../Document.h"

TEST_CASE ("Construct document from number and database", "[document from name]"){
    createConnection();

    SECTION("The document is in the database"){
        Document d = Document("123456");

        REQUIRE(d.getNumber() == "123456");
        REQUIRE(d.getType() == 9 );
        REQUIRE(d.getDate().toString() == "2012-12-23");
        REQUIRE(d.getDebitedParty() == "Ivan Ivanov");
    }

    SECTION("The document is not in the database"){
        Document d = Document("1234");

        REQUIRE(d.getNumber() == "");
        REQUIRE(d.getType() == 0 );
        REQUIRE(d.getDate().toString() == "1900-01-00");
        REQUIRE(d.getDebitedParty() == "");
    }
}

TEST_CASE ("Save document in the database", "[save document]"){
    createConnection();

    SECTION("Insert new document"){
        Document d = Document();
        d.setNumber("12345");
        d.setType(9);
        d.setDate(Date("2000-03-11"));
        d.setDebitedParty("Ivan Petkanov");

        d.save();
        std::string query = "select * from Document where documentNumber = '12345';";
        sql::Statement *statement = connection->createStatement();
        sql::ResultSet *result = statement->executeQuery(query);

        REQUIRE(result->next());
        REQUIRE(result->getString("documentNumber") == "12345");
        REQUIRE(result->getString("documentType") == "9");
        REQUIRE(result->getString("documentDate") == "2000-03-11");
        REQUIRE(result->getString("debitedParty") == "Ivan Petkanov");

        statement = connection->createStatement();
        statement->execute("delete from Document where documentNumber = '12345'");
    }

    SECTION("Insert existing document"){
        Document d = Document();
        d.setNumber("123456");

        REQUIRE(d.save() == -1);
    }
}

