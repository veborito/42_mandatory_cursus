#include "HumanB.hpp"
#include <iostream>
#include <string>

HumanB::HumanB(std::string name) : _name(name) {}

HumanB::~HumanB() {}

void HumanB::attack() {
    if (this->_weapon == NULL) {
        std::cout << this->_name << " attacks with their arm, i guess ?\n"; 
        return;
    }
    std::cout << this->_name << " attacks with their "
              << this->_weapon->getType() << '\n';
}

void HumanB::setWeapon(Weapon *weapon) {
    this->_weapon = weapon;
}
