#include "catch.hpp"
#include "../NumberInWords.h"

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
 }
