#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() {
    std::cout << "WrongCat constructor called\n";
    this->m_type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const& instance) {
    std::cout << "WrongCat copy constructor called\n";
    *this = instance;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called\n";
}

WrongCat& WrongCat::operator=(WrongCat const& rhs) {
    if (this != &rhs)
        this->m_type = rhs.getType();
    return *this;
}

void WrongCat::makeSound() const {
    std::cout << "MIIIAAAOUUUU...\n";
}
