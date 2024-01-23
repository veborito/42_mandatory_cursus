#ifndef DOG_H
#define DOG_H 
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
public:
    Dog();
    Dog(Dog const& instance);
    ~Dog();

    Dog& operator=(Dog const& rhs);

    Brain*      getBrain() const;
    void        makeSound() const;
private:
    Brain*  m_brain; 
};

#endif
