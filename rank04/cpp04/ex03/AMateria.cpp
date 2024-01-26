#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>
#include <iostream>

AMateria::AMateria() : _type("Default") {
    std::cout << "AMateria constructor called\n";
}

AMateria::AMateria(std::string const& type) {
    this->_type = type;
}
AMateria::AMateria(AMateria const& instance) {
    *this = instance;
}

AMateria& AMateria::operator=(AMateria const& instance) {
    (void)instance;
    return *this;
}

std::string const& AMateria::getType() const {
    return this->_type;
}

void AMateria::use(ICharacter& target) {
    std::cout << this->_type << "I don't know do something ?\n";
}

