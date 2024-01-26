#ifndef CHARACTER_H
#define CHARACTER_H

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string>

class Character : public ICharacter {
public:
    Character();
    Character(std::string name);
    Character(Character const& instance);
    ~Character();

    Character& operator=(Character const& rhs);

    std::string const & getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
private:
    std::string _name;
    AMateria* _inventaire[4];
};

#endif
