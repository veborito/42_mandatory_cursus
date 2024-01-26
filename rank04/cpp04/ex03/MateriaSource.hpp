
#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

#include "AMateria.hpp"

class MateriaSource
{
public:
    MateriaSource();
    MateriaSource(MateriaSource const& instance);
    ~MateriaSource();

    MateriaSource& operator=(MateriaSource const& rhs);

    void learnMateria(AMateria*);
    AMateria* createMateria(std::string const & type);
private:
    AMateria* _materias[4];
};

#endif

