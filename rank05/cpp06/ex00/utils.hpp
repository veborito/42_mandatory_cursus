#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>

std::string find_type(std::string const &literal);
void display_from_char(char const &c);
void display_from_int(int const &n);
void display_from_float(float const &f, int const &len);
void display_from_double(double const &d, int const &len);
int get_type(std::string const &type);
int after_dot(std::string const &literal);
bool edge_case(std::string const &literal);

#endif
