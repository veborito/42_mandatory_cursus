#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>


Cure::Cure() : AMateria("cure") {}
Cure::Cure(Cure const& instance) {
    *this = instance;
}
Cure::~Cure() {}
Cure& Cure::operator=(Cure const& instance) {
    (void) instance;
    return  *this;
}

AMateria* Cure::clone() const {
    return new Cure();
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *"  << '\n';
}
