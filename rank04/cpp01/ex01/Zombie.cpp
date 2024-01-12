#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie::Zombie() {
    std::cout << "Mr." << this->_name << " Zombie created\n";
}

Zombie::~Zombie() {
    std::cout << "Mr." << this->_name << " Zombie destructed\n";
}

void Zombie::setName(std::string name) {
    this->_name = name;
}

void Zombie::annonce() const {
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ...\n";
}
