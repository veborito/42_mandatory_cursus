#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name) : _name(name) {
    std::cout << "Mr." << this->_name << " Zombie created\n";
}

Zombie::~Zombie() {
    std::cout << "Mr." << this->_name << " Zombie destructed\n";
}

void Zombie::annonce() const {
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ...\n";
}
