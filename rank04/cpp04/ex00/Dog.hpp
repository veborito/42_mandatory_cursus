#ifndef DOG_H
#define DOG_H 
#include "Animal.hpp"

class Dog : public Animal {
public:
    Dog();
    Dog(Dog const& instance);
    ~Dog();

    Dog& operator=(Dog const& rhs);

    void        makeSound() const;
};

#endif
