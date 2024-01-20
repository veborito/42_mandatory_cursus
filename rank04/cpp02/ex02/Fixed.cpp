#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _value(0) {
}

Fixed::Fixed(Fixed const& instance) {
    *this = instance;
}

Fixed::Fixed(int const num) : _value(num) {
    this->_value = num * (1 << _numOfbits);
}

Fixed::Fixed(float const num) {
    // multiplying the value by 2 to the power of precision bits aka 8
    this->_value = int(roundf(num * float(1 << _numOfbits)));
}

Fixed::~Fixed() {}

 // ----------------------------- OPERATORS -----------------------------

Fixed& Fixed::operator=(Fixed const& rhs) {
    if (this != &rhs)
        this->_value = rhs.getRawBits();
    return *this;
}

Fixed   Fixed::operator+(Fixed const& rhs) const {
    return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed   Fixed::operator-(Fixed const& rhs) const {
    return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed   Fixed::operator*(Fixed const& rhs) const{
    return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed   Fixed::operator/(Fixed const& rhs) const{
    return Fixed(this->toFloat() / rhs.toFloat());
}


bool    Fixed::operator>(Fixed const& rhs) const {
    return this->_value > rhs.getRawBits();
}

bool    Fixed::operator<(Fixed const& rhs) const {
    return this->_value < rhs.getRawBits();
}

bool    Fixed::operator>=(Fixed const& rhs) const {
    return this->_value >= rhs.getRawBits();
}

bool    Fixed::operator<=(Fixed const& rhs) const {
    return this->_value <= rhs.getRawBits();
}

bool    Fixed::operator!=(Fixed const& rhs) const {
    return this->_value != rhs.getRawBits();
}

bool    Fixed::operator==(Fixed const& rhs) const {
    return this->_value == rhs.getRawBits();
}


Fixed&  Fixed::operator++() {
    this->_value++;
    return *this;
}
Fixed  Fixed::operator++(int) {
    Fixed tmp = *this;
    ++(*this);
    return tmp;
}
Fixed&  Fixed::operator--() {
    this->_value--;
    return *this;
}
Fixed  Fixed::operator--(int) {
    Fixed tmp = *this;
    --(*this);
    return tmp;
}

 // ----------------------------- MEMBER FUNCTIONS ----------------------------

int Fixed::getRawBits() const {
    return this->_value;
}

void Fixed::setRawBits(int const raw) {
    this->_value = raw;
}

float Fixed::toFloat() const {
    return float(this->_value) / float(1 << _numOfbits);
}

int Fixed::toInt() const {
    return this->_value / (1 << _numOfbits);
}

Fixed   Fixed::min(Fixed& a, Fixed& b) {
    return a < b ? a : b;
}
Fixed   Fixed::min(Fixed const& a, Fixed const& b) {
    return a < b ? a : b;
}
Fixed   Fixed::max(Fixed& a, Fixed& b) {
    return a > b ? a : b;
}
Fixed   Fixed::max(Fixed const& a, Fixed const& b) {
    return a > b ? a : b;
}

 // ----------------------------- STREAM -----------------------------

std::ostream&  operator<<(std::ostream& o, Fixed const& instance) {
    o << instance.toFloat();
    return o;
}
