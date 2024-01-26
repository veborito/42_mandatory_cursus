#ifndef ICHARACTER_H
#define ICHARACTER_H

#include "AMateria.hpp"
#include <string>

class Character : public ICharacter {
public:
    ~Character() {}
    std::string const & getName() const = 0;
    void equip(AMateria* m) = 0;
    void unequip(int idx) = 0;
    void use(int idx, Character& target) = 0;
};

#endif
