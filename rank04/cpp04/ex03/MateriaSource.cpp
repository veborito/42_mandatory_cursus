#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include <iostream>


MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; ++i)
        this->_materias[i] = nullptr;
}
MateriaSource::MateriaSource(MateriaSource const& instance) {
    *this = instance;
}
MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; ++i) {
        if (this->_materias[i]) {
            delete this->_materias[i];
            this->_materias[i] = nullptr;
        }
    }
}

MateriaSource& MateriaSource::operator=(MateriaSource const& rhs) {
    (void)rhs;
    return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
    for (int i = 0; i < 4; ++i) {
        if (this->_materias[i] == nullptr) {
            std::cout << "HERE\n";
            this->_materias[i] = m;
            std::cout << this->_materias[i]->getType() << '\n';
            return;
        }
    }
}
AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; ++i) {
        if (type == this->_materias[i]->getType())
            return this->_materias[i]->clone();
    }
    std::cout << "type de materia inconnu !\n";
    return 0;
}
