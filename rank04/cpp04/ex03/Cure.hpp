#ifndef CURE_H
#define CURE_H

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Cure : public AMateria {
public :
    Cure();
    Cure(Cure const& instance);
    ~Cure();

    Cure& operator=(Cure const& instance);

    AMateria* clone() const;
    void use(ICharacter& target);
};

#endif
