#include "catch.hpp"
#include "../InternationalPaymentOrder.h"

TEST_CASE ("Create Template International", "[create template]"){

        InternationalOrder order = InternationalOrder();
        order.setAmount(12);
        order.setReceiverBank(InternationalBank("12345678"));

        order.save(true);
        std::string lastID = getLastInsertedID();

        std::string query = std::string("select * from PaymentOrder p ") +
                            std::string("left join InternationalOrder i on p.order_id = i.order_id ") +
                            "where p.order_id = '" + lastID + "';";

        sql::Statement *statement = connection->createStatement();
        sql::ResultSet *result = statement->executeQuery(query);

        REQUIRE(result->next());
        REQUIRE(result->getString("type") == "I");
        REQUIRE(result->getString("isTemplate") == "1");
        REQUIRE(result->getString("senderIBAN") == "");
        REQUIRE(result->getString("senderName") == "");
        REQUIRE(result->getString("receiverIBAN") == "");
        REQUIRE(result->getString("receiverName") == "");
        REQUIRE(result->getString("currency") == "EUR");
        REQUIRE(result->getString("amount") == "12");
        REQUIRE(result->getString("description") == "");
        REQUIRE(result->getString("receiverAddress") == "");
        REQUIRE(result->getString("receiverCountry") == "");
        REQUIRE(result->getString("ExecutionPeriod") == "0");
        REQUIRE(result->getString("senderCharges") == "0");
        REQUIRE(result->getString("receiverCharges") == "0");
        REQUIRE(result->getString("receiverBankSWIFT") == "12345678");
        REQUIRE(result->getString("intermediaryBankSWIFT") == "");

        InternationalOrder::deleteFromDB(lastID);
 }
