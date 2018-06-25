#include "catch.hpp"
#include "../headers/NumberInWords.h"

TEST_CASE ("number in words", "[number in words]"){
    NumberInWords number = NumberInWords(12, 12);
    REQUIRE(number.getWholePartInWords() == "twelve");
    REQUIRE(number.getDecimalPartInWords() == "twelve");

    number = NumberInWords(12, 123);
    REQUIRE(number.getWholePartInWords() == "twelve");
    REQUIRE(number.getDecimalPartInWords() == "twelve");

    number = NumberInWords(12, -167);
    REQUIRE(number.getWholePartInWords() == "twelve");
    REQUIRE(number.getDecimalPartInWords() == "zero");

    number = NumberInWords(-342, 1);
    REQUIRE(number.getWholePartInWords() == "zero");
    REQUIRE(number.getDecimalPartInWords() == "one");
 }
