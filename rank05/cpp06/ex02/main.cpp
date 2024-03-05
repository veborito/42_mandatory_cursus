#include "Base.hpp"
#include <iostream>

int main() {
    Base base; 
    Base *pointer = base.generate();
    Base &reference= *pointer;

    std::cout << "This class is in fact : ";
    base.identify(pointer);
    std::cout << '\n'; 
    std::cout << "This class is in fact : ";
    base.identify(reference);
    std::cout << '\n'; 
    return 0;
}
