#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>

class ScalarConverter {
   public:
    ScalarConverter();
    ScalarConverter(ScalarConverter const &instance);
    virtual ~ScalarConverter();

    virtual ScalarConverter &operator=(ScalarConverter const &rhs) = 0;

    static void convert(std::string const &literal);
};

#endif
