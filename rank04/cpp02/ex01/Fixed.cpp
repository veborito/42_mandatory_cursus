#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(Fixed const& instance) {
    std::cout << "Copy constructor called\n";
    *this = instance;
}

Fixed::Fixed(int const num) : _value(num) {
    this->_value = num * (1 << _numOfbits);
    std::cout << "Int constructor called\n";
}

Fixed::Fixed(float const num) {
    // multiplying the value by 2 to the power of precision bits aka 8
    this->_value = int(roundf(num * float(1 << _numOfbits)));
    std::cout << "Float constructor called\n";
}

Fixed::~Fixed() {
    std::cout << "Destructor called\n";
}

Fixed& Fixed::operator=(Fixed const& rhs) {
    std::cout << "Copy assignment operator called\n";
    if (this != &rhs)
        this->_value = rhs.getRawBits();
    return *this;
}

int Fixed::getRawBits() const {
    return this->_value;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "Value set to : " << raw << '\n';
    this->_value = raw;
}

float Fixed::toFloat() const {
    return float(this->_value) / float(1 << _numOfbits);
}

int Fixed::toInt() const {
    return this->_value / (1 << _numOfbits);
}

std::ostream&  operator<<(std::ostream& o, Fixed const& instance) {
    o << instance.toFloat();
    return o;
}
