#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "AMateria.hpp"
#include "garbage.hpp"
#include <string>
#include <iostream>

Character::Character() : _name("Mec Lambda") {
    for (int i = 0; i < 4; ++i)
        this->_inventaire[i] = nullptr;
}
Character::Character(std::string name) : _name(name) {
    for (int i = 0; i < 4; ++i)
        this->_inventaire[i] = nullptr;
}
Character::Character(Character const& instance) {
    for (int i = 0; i < 4; ++i) {
        if (instance._inventaire[i]->getType() == "ice")
            this->_inventaire[i] = new Ice();
        else
            this->_inventaire[i] = new Cure();
    }
    this->_name = instance.getName();
}
Character::~Character() {
    for (int i = 0; i < 4; ++i) {
        if (this->_inventaire[i]) {
            delete this->_inventaire[i];
            this->_inventaire[i] = nullptr;
        }
    }
}

Character& Character::operator=(Character const& rhs) {
    for (int i = 0; i < 4; ++i) {
        delete this->_inventaire[i];
        if (rhs._inventaire[i]->getType() == "ice")
            this->_inventaire[i] = new Ice();
        else
            this->_inventaire[i] = new Cure();
    } 
    this->_name = rhs.getName();
    return *this;
}

std::string const & Character::getName() const {
    return this->_name;
}

void Character::equip(AMateria* m) {
    for (int i = 0; i < 4; ++i) {
        if (this->_inventaire[i] == nullptr) {
            this->_inventaire[i] = m;
            return;
        }
    }
}
void Character::unequip(int idx) {
    addToGarb(this->_inventaire[idx]);
    this->_inventaire[idx] = nullptr;
}
void Character::use(int idx, ICharacter& target) {
    if (idx < 4 && idx >= 0) {
        if (this->_inventaire[idx]) {
            this->_inventaire[idx]->use(target);
            return;
        }
    }
    std::cout << "I don't know what are you tryinig to use\n";
}
