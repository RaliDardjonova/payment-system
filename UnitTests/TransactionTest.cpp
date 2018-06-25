#include "catch.hpp"
#include "../headers/Transaction.h"
#include "../headers/OrdinaryOrder.h"
#include "../headers/FromToBudgetOrder.h"

TEST_CASE("Save transaction", "[save transaction]"){
    createConnection();

    SECTION("transaction with ordinary order"){
        Transaction transaction = Transaction((new OrdinaryOrder())->clone());
        transaction.setStatus(InProgress);
        transaction.setSignDate(Date());
        transaction.save();
        std::string transactionLastID = getLastInsertedID();

        std::string query = std::string("select * from ") +
                            std::string("Transaction t left join PaymentOrder p on t.order_id = p.order_id ") +
                            std::string("left join OrdinaryOrder o on p.order_id = o.order_id ") +
                            "where trans_id = '" + transactionLastID + "';";
        sql::Statement *statement = connection->createStatement();
        sql::ResultSet *result = statement->executeQuery(query);

        REQUIRE(result->next());
        REQUIRE(result->getString("signDate") == "1900-01-01");
        REQUIRE(result->getString("status") == "0");
        REQUIRE(result->getString("type") == "C");
        REQUIRE(result->getString("isTemplate") == "0");
        REQUIRE(result->getString("senderIBAN") == "");
        REQUIRE(result->getString("senderName") == "");
        REQUIRE(result->getString("receiverIBAN") == "");
        REQUIRE(result->getString("receiverName") == "");
        REQUIRE(result->getString("amount") == "0");
        REQUIRE(result->getString("description") == "");
        REQUIRE(result->getString("settlementSystem") == "0");

        Transaction::deleteFromDB(transactionLastID);
    }

    SECTION("transaction with FromToBudget order"){
        FromToBudgetOrder order = FromToBudgetOrder();
        order.setDocument(Document("123456"));
        Transaction transaction = Transaction(order.clone());
        transaction.setStatus(InProgress);
        transaction.setSignDate(Date());
        transaction.save();
        std::string transactionLastID = getLastInsertedID();

        std::string query = std::string("select * from ") +
                            std::string("Transaction t left join PaymentOrder p on t.order_id = p.order_id ") +
                            std::string("left join FromToBudgetOrder f on p.order_id = f.order_id ") +
                            "where trans_id = '" + transactionLastID + "';";
        sql::Statement *statement = connection->createStatement();
        sql::ResultSet *result = statement->executeQuery(query);

        REQUIRE(result->next());
        REQUIRE(result->getString("signDate") == "1900-01-01");
        REQUIRE(result->getString("status") == "0");
        REQUIRE(result->getString("type") == "B");
        REQUIRE(result->getString("isTemplate") == "0");
        REQUIRE(result->getString("senderIBAN") == "");
        REQUIRE(result->getString("senderName") == "");
        REQUIRE(result->getString("receiverIBAN") == "");
        REQUIRE(result->getString("receiverName") == "");
        REQUIRE(result->getString("amount") == "0");
        REQUIRE(result->getString("description") == "");
        REQUIRE(result->getString("relevantPaymentStartDate") == "1900-01-01");
        REQUIRE(result->getString("relevantPaymentEndDate") == "1900-01-01");
        REQUIRE(result->getString("paymentType") == "0");
        REQUIRE(result->getString("settlementSystem") == "0");
        REQUIRE(result->getString("documentNumber") == "123456");

        Transaction::deleteFromDB(transactionLastID);
    }
}

TEST_CASE("Get order ID from DB", "[get order_id]"){
    createConnection();
    Transaction transaction = Transaction((new OrdinaryOrder())->clone());
    transaction.save();
    std::string transactionLastID = getLastInsertedID();
    std::string query = "select order_id from Transaction where trans_id = '" + transactionLastID + "';";
    sql::Statement *statement = connection->createStatement();
    sql::ResultSet *result = statement->executeQuery(query);

    REQUIRE(result->next());
    REQUIRE(result->getString("order_id") == Transaction::getOrderID(transactionLastID));

    Transaction::deleteFromDB(transactionLastID);
}

TEST_CASE("Delete transaction from DB", "[delete from DB]"){
    createConnection();
    Transaction transaction = Transaction((new OrdinaryOrder())->clone());
    transaction.save();
    std::string transactionLastID = getLastInsertedID();
    std::string query = "select order_id from Transaction where trans_id = '" + transactionLastID + "';";

    Transaction::deleteFromDB(transactionLastID);
    sql::Statement *statement = connection->createStatement();
    sql::ResultSet *result = statement->executeQuery(query);

    REQUIRE(result->next() == false);
}
