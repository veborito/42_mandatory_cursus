#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>
#include <iostream>

AMateria::AMateria() : _type("Default") {
    std::cout << "AMateria constructor called\n";
}
