#include "ClapTrap.hpp"
#include <iostream>
#include <string>

ClapTrap::ClapTrap() 
    : _name("ClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "Default constructor called\n";
}

ClapTrap::ClapTrap(ClapTrap const& instance) {
    std::cout << "Copy constructor called\n";
    *this = instance;
}
ClapTrap::ClapTrap(std::string name) 
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "Argument constructor called\n";
}

ClapTrap::~ClapTrap() {
    std::cout << "Destructor called\n";
}

ClapTrap& ClapTrap::operator=(ClapTrap const& rhs) {
    if (this != &rhs) {
        this->_name = rhs.getName();
        this->_hitPoints = rhs.getHitPoints();
        this->_energyPoints = rhs.getEnergyPoints();
        this->_attackDamage = rhs.getAttackDamage();
    }
    return *this;
}

std::string ClapTrap::getName() const {
    return this->_name;
}

int ClapTrap::getHitPoints() const {
    return this->_hitPoints;
}

int ClapTrap::getEnergyPoints() const {
    return this->_energyPoints;
}

int ClapTrap::getAttackDamage() const {
    return this->_attackDamage;
}

std::string ClapTrap::stringRepr() const {
    return this->getName() + " / Hit Points: "
            + std::to_string(this->getHitPoints()) + " / Energy Points: "
            + std::to_string(this->getEnergyPoints()) + " / Attack Damage: "
            + std::to_string(this->getAttackDamage());
}

void ClapTrap::attack(std::string const& target) {
    if (this->_hitPoints == 0) {
        std::cout << "ClapTrap " << this->_name << " is broken\n";
        return;
    }
    else if (this->_energyPoints == 0) {
        std::cout << "ClapTrap " << this->_name << " has no energy!\n";
        return;
    }

    std::cout << "ClapTrap " << this->_name << " attacks " << target 
              << ", causing " << this->_attackDamage << " points of damage!\n"; 
    this->_energyPoints -= 1;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->_hitPoints == 0) {
        std::cout << this->_name << " is broken\n";
        return;
    }
    std::cout << this->_name << " took " << amount 
              << " points of damage!\n";
    this->_hitPoints -= amount;
    if (this->_hitPoints < 0)
        this->_hitPoints = 0;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->_hitPoints == 0) {
        std::cout << this->_name << " is broken\n";
        return;
    }
    else if (this->_energyPoints == 0) {
        std::cout << this->_name << " has no energy!\n";
        return;
    }
    std::cout << this->_name << " repairs " << amount
              << " points!\n";
    this->_hitPoints += amount;
    this->_energyPoints -= 1;
}

std::ostream& operator<<(std::ostream& o, ClapTrap const& instance) {
    o << instance.stringRepr();
    return o;
}
