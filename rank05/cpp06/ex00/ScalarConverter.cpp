#include "ScalarConverter.hpp"
#include "utils.hpp"

#include <exception>
#include <iostream>
#include <string>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter const &instance) {
    *this = instance;
}
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(std::string const &literal) {
    if (!edge_case(literal))
        return ;
    switch (get_type(find_type(literal))) {
        case 0: {
            char c = literal[0];
            display_from_char(c);
            break;
        }
        case 1: {
            try {
                int n = std::stoi(literal);
                display_from_int(n);
            } catch (std::exception &e) {
                std::cerr << "Error: int too big\n";
            }
            break;
        }
        case 2: {
            try {
                float f = std::stof(literal);
                display_from_float(f, after_dot(literal));
            } catch (std::exception &e) {
                std::cerr << "Error: float too big\n";
            }
            break;
        }
        case 3: {
            try {
                double d = std::stod(literal);
                display_from_double(d, after_dot(literal));
            } catch (std::exception &e) {
                std::cerr << "Error: double too big\n";
            }
            break;
        }
    }
}

