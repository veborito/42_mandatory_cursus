#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>


Ice::Ice() : AMateria("ice") {}
Ice::Ice(Ice const& instance) {
    *this = instance;
}
Ice::~Ice() {}
Ice& Ice::operator=(Ice const& instance) {
    (void) instance;
    return  *this;
}

AMateria* Ice::clone() const {
    return new Ice();
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
