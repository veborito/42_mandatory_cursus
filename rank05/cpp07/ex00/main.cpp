#include "whatever.hpp"
#include <iostream>

int main(void) {
    int a = 2;
    int b = 3;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    ::swap(a, b);
    std::cout << "Apres ::swap, a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    std::cout << "c = " << c << ", d = " << d << std::endl;
    ::swap(c, d);
    std::cout << "Apres ::swap, c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
    std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
	double e[2] = {2.2, 3.0};
    std::cout << "e0 = " << e[0] << ", e1 = " << e[1] << std::endl;
    ::swap(e[0], e[1]);
    std::cout << "Apres ::swap, e0 = " << e[0] << ", e1 = " << e[1] << std::endl;
    std::cout << "min( e0, e1 ) = " << ::min(e[0], e[1]) << std::endl;
    std::cout << "max( e0, e1 ) = " << ::max(e[0], e[1]) << std::endl;
    return 0;
}
