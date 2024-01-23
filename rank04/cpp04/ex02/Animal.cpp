#include "Animal.hpp"
#include <iostream>
#include <string>

Animal::Animal() : m_type("Animal") {
    std::cout << "Animal constructor called\n";
}

Animal::Animal(Animal const& instance) {
    std::cout << "Animal copy constructor called\n";
    *this = instance;
}

Animal::~Animal() {
    std::cout << "Animal destructor called\n";
}

Animal& Animal::operator=(Animal const& rhs) {
    if (this != &rhs)
        this->m_type = rhs.getType();
    return *this;
}

std::string Animal::getType() const {
    return this->m_type;
}

void Animal::makeSound() const {
    std::cout << "Animal makes a sound\n";
}
