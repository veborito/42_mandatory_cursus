#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(Fixed const& instance) {
    std::cout << "Copy constructor called\n";
    *this = instance;
}

Fixed::~Fixed() {
    std::cout << "Destructor called\n";
}

Fixed& Fixed::operator=(Fixed const& rhs) {
    std::cout << "Copy assignment operator called\n";
    this->_value = rhs.getRawBits();
    return *this;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called\n";
    return this->_value;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "Value set to : " << raw << '\n';
    this->_value = raw;
}
