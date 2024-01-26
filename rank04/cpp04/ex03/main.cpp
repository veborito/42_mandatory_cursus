#include <string>
#include "garbage.hpp"
#include "ICharacter.hpp"
#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

t_garb *sol = nullptr; 

void addToGarb(AMateria* item) {
    if (!sol) {
        sol = new t_garb;
        sol->next = nullptr;
        sol->item = item;
        return;
    }
    t_garb* newItem = new t_garb;
    newItem->item = item;
    newItem->next = nullptr;
    t_garb* tmp;
    tmp = sol;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = newItem;
}

int main() {
    MateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);

    me->unequip(0);

    delete bob;
    delete me;
    delete src;

    t_garb *temp = sol;
    while (temp) {
        delete temp->item;
        temp = temp->next;
    }
    while (sol) {
        temp = sol;
        sol = sol->next;
        delete temp;
    }
    return 0;
}
