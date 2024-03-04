#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>

class ScalarConverter {
   public:
    virtual ScalarConverter &operator=(ScalarConverter const &rhs) = 0;

    static void convert(std::string const &literal);

   private:
    ScalarConverter();
    ScalarConverter(ScalarConverter const &instance);
    virtual ~ScalarConverter();
};

#endif
