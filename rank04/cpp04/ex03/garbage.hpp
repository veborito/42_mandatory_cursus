#ifndef GARBAGE_H
#define GARBAGE_H

class AMateria;

typedef struct s_garb {
    s_garb *next;
    AMateria* item;
} t_garb;

void addToGarb(AMateria* item);

#endif
