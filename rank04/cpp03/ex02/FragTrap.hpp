#ifndef FRAGTRAP_H
#define FRAGTRAP_H
#include "ClapTrap.hpp"
#include <string>

class FragTrap : public ClapTrap {
public:
    FragTrap();
    FragTrap(FragTrap const& instance);
    FragTrap(std::string name);
    ~FragTrap();
    
    void    highFivesGuys();

};

#endif
