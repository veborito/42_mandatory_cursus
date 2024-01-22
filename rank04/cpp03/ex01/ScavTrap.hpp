#ifndef SCAVTRAP_H
#define SCAVTRAP_H
#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public ClapTrap {
public:
    ScavTrap();
    ScavTrap(ScavTrap const& instance);
    ScavTrap(std::string name);
    ~ScavTrap();
    
    void    attack(std::string const& target);
    void    guardGate();

};

#endif
