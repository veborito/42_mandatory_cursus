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

    Fixed&   operator=(Fixed const& rhs);

    int     getRawBits() const;
    void    setRawBits(int const raw);
    float   toFloat() const;
    int     toInt() const;
private:
    int              _value;
    int static const _numOfbits = 8;
};

std::ostream& operator<<(std::ostream& o, Fixed const& instance);

#endif
