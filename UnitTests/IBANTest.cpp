#include "catch.hpp"
#include "../IBAN.h"

TEST_CASE ("Get bank BIC", "[get BIC]"){
    createConnection();

    SECTION("Get existing bank BIC"){
        IBAN iban = IBAN("BG58RZBB91555087474816");

        REQUIRE(iban.getBIC() == "RZBBBGSF");
    }
 }

 TEST_CASE("Check IBAN correctness", "[IBAN correctness]"){

    SECTION("Check correct IBAN"){
        REQUIRE(IBAN::isCorrect("BG58RZBB91555087474816") == 1);
        REQUIRE(IBAN::isCorrect("BG26RZBB91551036528703") == 1);
    }

    SECTION("Check incorrect IBAN"){
        REQUIRE(IBAN::isCorrect("BG58RZBB91555087474818") == 0);
        REQUIRE(IBAN::isCorrect("BG58RZBB91555087474814") == 0);
    }
 }
