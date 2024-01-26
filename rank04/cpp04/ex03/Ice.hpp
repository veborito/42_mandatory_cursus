#ifndef ICE_H
#define ICE_H

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Ice : public AMateria {
public :
    Ice();
    Ice(Ice const& instance);
    ~Ice();

    Ice& operator=(Ice const& instance);

    AMateria* clone() const;
    void use(ICharacter& target);
};

#endif
