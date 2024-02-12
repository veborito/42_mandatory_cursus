#include "ScalarConverter.hpp"
#include <iostream>

int main() {

    ScalarConverter::convert("42.0f");
    ScalarConverter::convert("-42.0f");
    ScalarConverter::convert("-42.012f");
    ScalarConverter::convert("432445095482353452345235235235235235342323424234234242554234523452345132413241423412412341234123412341234134123412341234123412341234123412341234534");
    ScalarConverter::convert("nan");
    ScalarConverter::convert("nanf");
    ScalarConverter::convert("-inf");
    ScalarConverter::convert("+inf");
    ScalarConverter::convert("-inff");
    ScalarConverter::convert("-112223321342434234234234234212.0");
    return 0;
}
