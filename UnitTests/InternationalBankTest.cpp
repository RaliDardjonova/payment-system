
#include "catch.hpp"
#include "../headers/InternationalBank.h"


TEST_CASE("Fetch bank name from database", "[fetch name]"){
    createConnection();

    InternationalBank b1 = InternationalBank("12345678");
    InternationalBank b2 = InternationalBank("11111111");


    REQUIRE(b1.getBankName() == "nqkwa banka1");
    REQUIRE(b2.getBankName() == "");
}

TEST_CASE("Fetch bank address from database", "[fetch address]"){
    createConnection();

    InternationalBank b1 = InternationalBank("12345678");
    InternationalBank b2 = InternationalBank("11111111");


    REQUIRE(b1.getBankAddress() == "sofiq, adresa na nqkwata banka");
    REQUIRE(b2.getBankAddress() == "");
}

TEST_CASE("Set SWIFT", "[set SWIFT]")
{
    InternationalBank b = InternationalBank();

    SECTION( "set valid SWIFT" ) {
        b.setBankSWIFT("12345678");
        REQUIRE(b.getBankSWIFT() == "12345678");
    }

    SECTION("set shorter SWIFT"){
        b.setBankSWIFT("1234567");
        REQUIRE(b.getBankSWIFT() == "00000000");
    }

    SECTION("set longer SWIFT"){
        b.setBankSWIFT("123456789");
        REQUIRE(b.getBankSWIFT() == "00000000");
    }
}

TEST_CASE("Get SWIFT", "[get SWIFT]"){
    InternationalBank b1 = InternationalBank("12345678");
    InternationalBank b2 = InternationalBank("22222222");
    InternationalBank b3 = InternationalBank();


    REQUIRE(b1.getBankSWIFT() == "12345678");
    REQUIRE(b2.getBankSWIFT() == "22222222");
    REQUIRE(b3.getBankSWIFT() == "00000000");
}
