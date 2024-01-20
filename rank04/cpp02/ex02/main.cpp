#include "Fixed.hpp"
#include <iostream>

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;

    std::cout << Fixed::max( a, b ) << std::endl;
    std::cout << "\nEND OF MANDATORY TESTS\n\n";
    std::cout << Fixed::min( a, b ) << std::endl;

    std::cout << --a << std::endl;
    std::cout << a << std::endl;
    std::cout << a-- << std::endl;
    std::cout << a << std::endl;
    Fixed x(50.265f);
    Fixed y(20);
    Fixed z(y);
    Fixed r(x);

    std::cout << (x / y) << '\n';
    std::cout << (x * y) << '\n';
    std::cout << (x + y) << '\n';
    std::cout << (x - y) << '\n';
    std::cout << std::boolalpha;
    std::cout << (x < y) << '\n';
    std::cout << (x > y) << '\n';
    std::cout << (x == y) << '\n';
    std::cout << (x == r) << '\n';
    std::cout << (y == z) << '\n';
    return 0;
}
