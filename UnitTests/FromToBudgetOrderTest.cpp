#include "catch.hpp"
#include "../FromToBudgetOrder.h"

TEST_CASE ("Get ammount in words", "[ammount in words]"){

        FromToBudgetOrder order = FromToBudgetOrder();
        order.setAmount(12);
        REQUIRE(order.getAmountInWords() == "twelve leva");

        order.setAmount(129);
        REQUIRE(order.getAmountInWords() == "one hundred twenty nine leva");
 }

 TEST_CASE ("Create Template fromToBudget", "[create template]"){

        FromToBudgetOrder order = FromToBudgetOrder();
        order.setAmount(12);
        order.setDocument(Document("123456"));

        order.save(true);
        std::string lastID = getLastInsertedID();

        std::string query = "select * from FromToBudgetOrder where order_id = '" + lastID + "';";
        sql::Statement *statement = connection->createStatement();
        sql::ResultSet *result = statement->executeQuery(query);
        REQUIRE(result->next());
        REQUIRE(result->getString("receiverIBAN") == "");
        REQUIRE(result->getString("receiverName") == "");
        REQUIRE(result->getString("amount") == "12");
        REQUIRE(result->getString("description") == "");
        REQUIRE(result->getString("relevantPaymentStartDate") == "1900-01-00");
        REQUIRE(result->getString("relevantPaymentEndDate") == "1900-01-00");
        REQUIRE(result->getString("paymentType") == "0");
        REQUIRE(result->getString("settlementSystem") == "0");
        REQUIRE(result->getString("documentNumber") == "123456");

        statement = connection->createStatement();
        statement->execute("delete from FromToBudgetOrder where order_id = " + lastID + ";");
        statement->execute("delete from PaymentOrder where order_id = " + lastID + ";");
 }
