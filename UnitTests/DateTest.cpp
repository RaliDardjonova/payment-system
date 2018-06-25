#include "catch.hpp"
#include "../headers/Date.h"

TEST_CASE("get date in string", "date to string"){
    SECTION("Set valid date"){
        Date date = Date();
        REQUIRE(date.toString() == "1900-01-01");

        date.setDay(3);
        date.setMonth(4);
        date.setYear(1991);
        REQUIRE(date.toString() == "1991-04-03");
    }

    SECTION("Set invalid date"){
        Date date = Date();
        date.setDay(31);
        date.setMonth(-34);
        date.setYear(-121);
        REQUIRE(date.toString() == "1900-01-31");

        date = Date();
        date.setDay(32);
        date.setMonth(34);
        date.setYear(1911);
        REQUIRE(date.toString() == "1911-01-01");
    }
}

TEST_CASE ("Construct date from string", "[date from string]"){
    SECTION("Set valid date"){
        Date date = Date("2190-12-01");
        REQUIRE(date.toString() == "2190-12-01");

        date = Date("1901-03-28");
        REQUIRE(date.toString() == "1901-03-28");
    }

    SECTION("Set invalid date"){
        Date date = Date("13-3-1");
        REQUIRE(date.toString() == "1900-01-01");

        date = Date("1945-15-03");
        REQUIRE(date.toString() == "1945-01-03");

        date = Date("1945-12-33");
        REQUIRE(date.toString() == "1945-12-01");
    }
}
