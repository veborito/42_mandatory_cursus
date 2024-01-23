#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

Dog::Dog() {
    std::cout << "Dog constructor called\n";
    this->m_type= "Dog";
    this->m_brain = new Brain();
}

Dog::Dog(Dog const& instance) {
    std::cout << "Dog copy constructor called\n";
    this->m_type = instance.m_type;
    this->m_brain = new Brain(*instance.m_brain);
}

Dog::~Dog() {
    std::cout << "Dog destructor called\n";
    delete this->m_brain;
}

Dog& Dog::operator=(Dog const& rhs) {
    delete this->m_brain;
    this->m_brain = new Brain(*rhs.m_brain);
    return *this;
}

Brain* Dog::getBrain() const {
    return this->m_brain;
} 

void Dog::makeSound() const {
    std::cout << "WAAAAF WAF WAF...\n";
}
