#include "catch.hpp"
#include "../OrdinaryOrder.h"

 TEST_CASE ("Create Template ordinary", "[create template]"){

        OrdinaryOrder order = OrdinaryOrder();
        order.setAmount(12);

        order.save(true);
        std::string lastID = getLastInsertedID();

        std::string query = std::string("select * from PaymentOrder p ") +
                            std::string("left join OrdinaryOrder o on p.order_id = o.order_id ") +
                            "where p.order_id = '" + lastID + "';";
        sql::Statement *statement = connection->createStatement();
        sql::ResultSet *result = statement->executeQuery(query);

        REQUIRE(result->next());
        REQUIRE(result->getString("isTemplate") == "1");
        REQUIRE(result->getString("senderIBAN") == "");
        REQUIRE(result->getString("senderName") == "");
        REQUIRE(result->getString("receiverIBAN") == "");
        REQUIRE(result->getString("receiverName") == "");
        REQUIRE(result->getString("amount") == "12");
        REQUIRE(result->getString("description") == "");
        REQUIRE(result->getString("settlementSystem") == "0");

        OrdinaryOrder::deleteFromDB(lastID);
 }
