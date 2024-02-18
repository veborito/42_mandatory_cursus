#include <iomanip>
#include <iostream>
#include <limits>
#include <exception>

#include  "utils.hpp"

std::string find_type(std::string const &literal) {
    int len = literal.length();
    if (len == 1) {
        if (std::isdigit(literal[0])) return "int";
        return "char";
    }
    bool dot = false;
    for (int i = 1; i < static_cast<int>(literal.length() - 1); ++i) {
        if (!std::isdigit(literal[i]) and dot == true) {
            std::cerr << "Error: not a valid argument 1\n";
            return "";
        }
        if (!std::isdigit(literal[i]) and
            (literal[len - 1] != 'f' and literal[len - 1] != '.')) {
            if (literal[i] != '.') {
                std::cerr << "Error: not a valid argument 2\n";
                return "";
            }
            dot = true;
        }
    }
    if (literal[len - 1] == 'f' or literal == "+inff" or literal == "-inff" or
        literal == "nanf")
        return "float";
    if (dot) return "double";
    return "int";
}

void display_from_char(char const &c) {
    int n = static_cast<int>(c);
    float f = static_cast<float>(c);
    double d = static_cast<double>(c);

    std::cout << "char: " << c << '\n';
    std::cout << "int: " << n << '\n';
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << f << 'f' << '\n';
    std::cout << "double: " << d << '\n';
}

void display_from_int(int const &n) {
    try {
        char c = static_cast<char>(n);
        if (c > 33 and c < 127)
            std::cout << "char: " << c << '\n';
        else if (n < 0 or n > 127)
            std::cout << "char: impossible\n";
        else
            std::cout << "char: Non displayable\n";
    } catch (std::exception &e) {
        std::cout << "char: impossible\n";
    }
    float f = static_cast<float>(n);
    double d = static_cast<double>(n);

    std::cout << "int: " << n << '\n';
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << f << 'f' << '\n';
    std::cout << "double: " << d << '\n';
}

void display_from_float(float const &f, int const &len) {
    try {
        char c = static_cast<char>(f);
        if (c > 33 and c < 127)
            std::cout << "char: " << c << '\n';
        else if (f < 0 or f > 127)
            std::cout << "char: impossible\n";
        else
            std::cout << "char: Non displayable\n";
    } catch (std::exception &e) {
        std::cout << "char: impossible\n";
    }
    try {
        if (f > std::numeric_limits<int>::max() or
            f < std::numeric_limits<int>::min())
            std::cout << "int: impossible\n";
        else {
            int n = static_cast<int>(f);
            std::cout << "int: " << n << '\n';
        }
    } catch (std::exception &e) {
        std::cout << "int: impossible\n";
    }
    double d = static_cast<double>(f);
    std::cout << std::fixed << std::setprecision(len);
    std::cout << "float: " << f << 'f' << '\n';
    std::cout << "double: " << d << '\n';
}

void display_from_double(double const &d, int const &len) {
    try {
        char c = static_cast<char>(d);
        if (c > 33 and c < 127)
            std::cout << "char: " << c << '\n';
        else if (d < 0 or d > 127)
            std::cout << "char: impossible\n";
        else
            std::cout << "char: Non displayable\n";
    } catch (std::exception &e) {
        std::cout << "char: impossible\n";
    }
    try {
        if (d > std::numeric_limits<int>::max() or
            d < std::numeric_limits<int>::min())
            std::cout << "int: impossible\n";
        else {
            int n = static_cast<int>(d);
            std::cout << "int: " << n << '\n';
        }
    } catch (std::exception &e) {
        std::cout << "int: impossible\n";
    }
    if (d > std::numeric_limits<float>::max() or
        d < std::numeric_limits<float>::min())
        std::cout << "float: impossible\n";
    else {
        float f = static_cast<float>(d);
        std::cout << std::fixed << std::setprecision(len);
        std::cout << "float: " << f << 'f' << '\n';
    }
    std::cout << std::fixed << std::setprecision(len);
    std::cout << "double: " << d << '\n';
}

int get_type(std::string const &type) {
    std::string types[4] = {"char", "int", "float", "double"};
    for (int i = 0; i < 4; ++i) {
        if (type == types[i]) return i;
    }
    return -1;
}

int after_dot(std::string const &literal) {
    int len = literal.length();
    for (int i = 0; i < len; ++i) {
        if (literal[i] == '.') {
            if (literal[len - 1] == 'f') return (len - 1) - (i + 1);
            return len - (i + 1);
        }
    }
    return 1;
}

bool edge_case(std::string const &literal) {
    if (literal.empty()) {
        std::cerr << "Error : empty string\n";
        return false;
    }
    if (literal == "nanf" or literal == "+inff" or literal == "-inff") {
        float f = std::stof(literal);
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: " << f << 'f' << '\n';
        std::cout << "double: " << static_cast<double>(f) << '\n';
        return false;
    }
    if (literal == "nan" or literal == "+inf" or literal == "-inf") {
        double d = std::stod(literal);
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: " << static_cast<float>(d) << 'f' << '\n';
        std::cout << "double: " << d << '\n';
        return false;
    }
    if (literal.length() > 1 and (!std::isdigit(literal[0]) and
                                  literal[0] != '+' and literal[0] != '-')) {
        std::cerr << "Error: not a valid argument\n";
        return false;
    }
    return true;
}
