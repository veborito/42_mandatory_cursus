#include "Weapon.hpp"

Weapon::Weapon() {}
Weapon::~Weapon() {}

// on passe const& pour que la variable ne puisse pas etre accessible via la fonction
std::string const& Weapon::getType() const {
    return this->_type;
}
void Weapon::setType(std::string type) { this->_type = type; }
