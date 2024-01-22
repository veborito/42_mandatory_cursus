#include "Cat.hpp"
#include <iostream>

Cat::Cat() {
    std::cout << "Cat constructor called\n";
    this->m_type = "Cat";
}

Cat::Cat(Cat const& instance) {
    std::cout << "Cat copy constructor called\n";
    *this = instance;
}

Cat::~Cat() {
    std::cout << "Cat destructor called\n";
}

Cat& Cat::operator=(Cat const& rhs) {
    if (this != &rhs)
        this->m_type = rhs.getType();
    return *this;
}

void Cat::makeSound() const {
    std::cout << "MIIIAAAOUUUU...\n";
}
