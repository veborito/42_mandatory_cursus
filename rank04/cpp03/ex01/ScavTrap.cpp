#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>
#include <string>

ScavTrap::ScavTrap() : ClapTrap() { 
    this->_name = "ScavTrap";
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "Default ScavTrap constructor called\n";
}

ScavTrap::ScavTrap(ScavTrap const& instance) {
    std::cout << "ScavTrap Copy constructor called\n";
    *this = instance;
}
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) { 
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap argument constructor called\n";
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap Destructor called\n";
}

void ScavTrap::attack(std::string const& target) {
    if (this->_hitPoints == 0) {
        std::cout << "ScavTrap " << this->_name << " is broken\n";
        return;
    }
    else if (this->_energyPoints == 0) {
        std::cout << "ScavTrap " << this->_name << " has no energy!\n";
        return;
    }

    std::cout << "ScavTrap " << this->_name << " attacks " << target 
              << ", causing " << this->_attackDamage << " points of damage!\n"; 
    this->_energyPoints -= 1;
}

void ScavTrap::guardGate() {
    if (this->_hitPoints == 0) {
        std::cout << "FragTrap " << this->_name << " is broken!\n"; 
    }
    std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode!\n";
}
