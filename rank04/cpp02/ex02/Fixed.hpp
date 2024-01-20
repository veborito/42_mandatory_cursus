#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed {
public:
    Fixed();
    Fixed(int const num);
    Fixed(float const num);
    Fixed(Fixed const& instance);
    ~Fixed();

    Fixed&          operator=(Fixed const& rhs);
    Fixed           operator+(Fixed const& rhs) const;
    Fixed           operator-(Fixed const& rhs) const;
    Fixed           operator*(Fixed const& rhs) const;
    Fixed           operator/(Fixed const& rhs) const;

    bool            operator>(Fixed const& rhs) const;
    bool            operator<(Fixed const& rhs) const;
    bool            operator>=(Fixed const& rhs) const;
    bool            operator<=(Fixed const& rhs) const;
    bool            operator!=(Fixed const& rhs) const;
    bool            operator==(Fixed const& rhs) const;

    Fixed&          operator++();
    Fixed           operator++(int);
    Fixed&          operator--();
    Fixed           operator--(int);


    int             getRawBits() const;
    void            setRawBits(int const raw);
    float           toFloat() const;
    int             toInt() const;
    Fixed static    min(Fixed& a, Fixed& b);
    Fixed static    min(Fixed const& a, Fixed const& b);
    Fixed static    max(Fixed& a, Fixed& b);
    Fixed static    max(Fixed const& a, Fixed const& b);

private:
    int              _value;
    int static const _numOfbits = 8;
};

std::ostream& operator<<(std::ostream& o, Fixed const& instance);

#endif
