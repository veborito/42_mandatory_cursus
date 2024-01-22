#include "Dog.hpp"
#include <iostream>
#include <string>

Dog::Dog() {
    std::cout << "Dog constructor called\n";
    this->m_type= "Dog";
}

Dog::Dog(Dog const& instance) {
    std::cout << "Dog copy constructor called\n";
    *this = instance;
}

Dog::~Dog() {
    std::cout << "Dog destructor called\n";
}

Dog& Dog::operator=(Dog const& rhs) {
    if (this != &rhs)
        this->m_type = rhs.getType();
    return *this;
}

void Dog::makeSound() const {
    std::cout << "WAAAAF WAF WAF...\n";
}
