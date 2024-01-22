#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>
#include <string>

FragTrap::FragTrap() : ClapTrap() { 
    this->_name = "FragTrap";
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "Default FragTrap constructor called\n";
}

FragTrap::FragTrap(FragTrap const& instance) {
    std::cout << "FragTrap Copy constructor called\n";
    *this = instance;
}
FragTrap::FragTrap(std::string name) : ClapTrap(name) { 
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap argument constructor called\n";
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap Destructor called\n";
}

FragTrap& FragTrap::operator=(FragTrap const& rhs) {
    if (this != &rhs) {
        this->_name = rhs.getName();
        this->_hitPoints = rhs.getHitPoints();
        this->_energyPoints = rhs.getEnergyPoints();
        this->_attackDamage = rhs.getAttackDamage();
    }
    return *this;
}

void FragTrap::highFivesGuys() {
    if (this->_hitPoints == 0) {
        std::cout << "FragTrap " << this->_name << " is broken!\n";
        return;
    }
    std::cout << "FragTrap " << this->_name << " high fives you!\n";
}
