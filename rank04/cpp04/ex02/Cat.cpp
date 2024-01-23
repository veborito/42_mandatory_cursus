#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

Cat::Cat() {
    std::cout << "Cat constructor called\n";
    this->m_type = "Cat";
    this->m_brain = new Brain();
}

Cat::Cat(Cat const& instance) {
    std::cout << "Cat copy constructor called\n";
    this->m_type = instance.m_type;
    this->m_brain = new Brain(*instance.m_brain);
}

Cat::~Cat() {
    std::cout << "Cat destructor called\n";
    delete this->m_brain;
}

Cat& Cat::operator=(Cat const& rhs) {
    delete this->m_brain;
    this->m_brain = new Brain(*rhs.m_brain);
    return *this;
}

Brain* Cat::getBrain() const {
    return this->m_brain;
}

void Cat::makeSound() const {
    std::cout << "MIIIAAAOUUUU...\n";
}
