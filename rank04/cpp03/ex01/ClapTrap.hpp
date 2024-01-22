#ifndef CLAPTRAP_H
#define CLAPTRAP_H
#include <string>
#include <iostream>

class ClapTrap {
public:
    ClapTrap();
    ClapTrap(ClapTrap const& instance);
    ClapTrap(std::string name);
    ~ClapTrap();

    ClapTrap&   operator=(ClapTrap const& rhs);

    std::string getName() const;
    int         getHitPoints() const;
    int         getEnergyPoints() const;
    int         getAttackDamage() const;
    std::string stringRepr() const;

    void        attack(std::string const& target);
    void        takeDamage(unsigned int amount);
    void        beRepaired(unsigned int amount);
protected:
    std::string _name;
    int         _hitPoints;
    int         _energyPoints;
    int         _attackDamage;
};

std::ostream& operator<<(std::ostream& o, ClapTrap const& instance);

#endif
