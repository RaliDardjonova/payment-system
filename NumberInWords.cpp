#include "NumberInWords.h"

std::vector<std::string> NumberInWords::ones = {"","one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
std::vector<std::string> NumberInWords::teens = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen","sixteen", "seventeen", "eighteen", "nineteen"};
std::vector<std::string> NumberInWords::tens = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

NumberInWords::NumberInWords(){
    wholePart = 0;
    decimalPart = 0;
}

NumberInWords::NumberInWords(const NumberInWords& other){
    setWholePart(other.getWholePart());
    setDecimalPart(other.getDecimalPart());
}

NumberInWords::NumberInWords(long long newWholePart, unsigned int newDecimalPart){
    setWholePart(newWholePart);
    setDecimalPart(newDecimalPart);
}

NumberInWords::~NumberInWords(){}

void NumberInWords::setWholePart(long long newWholePart){
    wholePart = newWholePart;
}

void NumberInWords::setDecimalPart(unsigned int newDecimalPart){
    if(newDecimalPart <= 100){
        decimalPart = newDecimalPart;
    }
}

long long NumberInWords::getWholePart() const {
    return wholePart;
}

int NumberInWords::getDecimalPart() const {
    return decimalPart;
}

std::string NumberInWords::getWholePartInWords(){
    return nameForNumber(wholePart);
}

std::string NumberInWords::getDecimalPartInWords(){
    return nameForNumber(decimalPart);
}

std::string NumberInWords::nameForNumber (long long number) {
        if (number < 10) {
            return ones[number];
        } else if (number < 20) {
            return teens [number - 10];
        } else if (number < 100) {
            return tens[number / 10] + ((number % 10 != 0) ? " " + nameForNumber(number % 10) : "");
        } else if (number < 1000) {
            return nameForNumber(number / 100) + " hundred" + ((number % 100 != 0) ? " " + nameForNumber(number % 100) : "");
        } else if (number < 1000000) {
            return nameForNumber(number / 1000) + " thousand" + ((number % 1000 != 0) ? " " + nameForNumber(number % 1000) : "");
        } else if (number < 1000000000) {
            return nameForNumber(number / 1000000) + " million" + ((number % 1000000 != 0) ? " " + nameForNumber(number % 1000000) : "");
        } else if (number < 1000000000000) {
            return nameForNumber(number / 1000000000) + " billion" + ((number % 1000000000 != 0) ? " " + nameForNumber(number % 1000000000) : "");
        }
        return "error";
}
