#ifndef ICE_H
#define ICE_H

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : AMateria {
public :
    Cure();
    Cure(Cure const& instance);
    ~Cure();

    Cure& operator=(Cure const& instance);

    AMateria* clone() const;
    void use(ICharacter& target);
};

#endif
