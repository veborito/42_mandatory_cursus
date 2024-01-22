#include "WrongAnimal.hpp"
#include <iostream>
#include <string>

WrongAnimal::WrongAnimal() : m_type("WrongAnimal") {
    std::cout << "WrongAnimal constructor called\n";
}

WrongAnimal::WrongAnimal(WrongAnimal const& instance) {
    std::cout << "WrongAnimal copy constructor called\n";
    *this = instance;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called\n";
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const& rhs) {
    if (this != &rhs)
        this->m_type = rhs.getType();
    return *this;
}

std::string WrongAnimal::getType() const {
    return this->m_type;
}

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal makes a sound\n";
}
