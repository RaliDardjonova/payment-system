#include "catch.hpp"
#include "../headers/FromToBudgetOrder.h"

TEST_CASE ("Get ammount in words", "[ammount in words]"){
    FromToBudgetOrder order = FromToBudgetOrder();
    order.setAmount(12);
    REQUIRE(order.getAmountInWords() == "twelve leva");

    order.setAmount(129);
    REQUIRE(order.getAmountInWords() == "one hundred twenty nine leva");

    order.setAmount(1234);
    REQUIRE(order.getAmountInWords() == "one thousand two hundred thirty four leva");

    order.setAmount(10.10);
    REQUIRE(order.getAmountInWords() == "ten leva and ten stotinki");

    order.setAmount(455.45);
    REQUIRE(order.getAmountInWords() == "four hundred fifty five leva and forty five stotinki");

    order.setAmount(0.98);
    REQUIRE(order.getAmountInWords() == "zero leva and ninety eight stotinki");
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
    REQUIRE(result->getString("relevantPaymentStartDate") == "1900-01-01");
    REQUIRE(result->getString("relevantPaymentEndDate") == "1900-01-01");
    REQUIRE(result->getString("paymentType") == "0");
    REQUIRE(result->getString("settlementSystem") == "0");
    REQUIRE(result->getString("documentNumber") == "123456");

    FromToBudgetOrder::deleteFromDB(lastID);
 }

 TEST_CASE("Delete fromToBudget from DB", "[delet from DB]"){
    FromToBudgetOrder order = FromToBudgetOrder();
    order.setDocument(Document("123456"));
    order.save(true);
    std::string lastID = getLastInsertedID();
    FromToBudgetOrder::deleteFromDB(lastID);

    std::string query = std::string("select * from PaymentOrder p ") +
                            std::string("left join FromToBudgetOrder i on p.order_id = i.order_id ") +
                            "where p.order_id = '" + lastID + "' or i.order_id = '" + lastID + "';";
    sql::Statement *statement = connection->createStatement();
    sql::ResultSet *result = statement->executeQuery(query);

    REQUIRE(result->next() == false);
 }
