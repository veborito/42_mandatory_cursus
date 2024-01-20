#ifndef FIXED_H
#define FIXED_H

class Fixed {
public:
    Fixed();
    Fixed(Fixed const& instance);
    ~Fixed();

    Fixed&   operator=(Fixed const& rhs);

    int     getRawBits() const;
    void    setRawBits(int const raw);
private:
    int              _value;
    int static const _numOfbits = 8;
};

#endif
