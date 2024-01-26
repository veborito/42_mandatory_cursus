#ifndef ICE_H
#define ICE_H

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : AMateria {
public :
    Ice();
    Ice(Ice const& instance);
    ~Ice();

    Ice& operator=(Ice const& instance);

    AMateria* clone() const;
    void use(ICharacter& target);
};

#endif
