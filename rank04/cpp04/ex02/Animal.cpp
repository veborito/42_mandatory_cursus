#include "Animal.hpp"
#include <iostream>
#include <string>

AAnimal::AAnimal() : m_type("AAnimal") {
    std::cout << "AAnimal constructor called\n";
}

AAnimal::AAnimal(AAnimal const& instance) {
    std::cout << "AAnimal copy constructor called\n";
    *this = instance;
}

AAnimal::~AAnimal() {
    std::cout << "AAnimal destructor called\n";
}

AAnimal& AAnimal::operator=(AAnimal const& rhs) {
    if (this != &rhs)
        this->m_type = rhs.getType();
    return *this;
}

std::string AAnimal::getType() const {
    return this->m_type;
}

