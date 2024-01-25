#ifndef AMATERIA_H
#define AMATERIA_H

#include "ICharacter.hpp"
#include <string>

class AMateria
{
protected:
    std::string _type;
public:
    AMateria();
    AMateria(std::string const & type);
    AMateria(AMateria const& instance);

    AMateria& operator=(AMateria const& instance);

    std::string const & getType() const; //Returns the materia type
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

#endif
