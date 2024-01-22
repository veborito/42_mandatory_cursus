#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>

class Animal {
public:
    Animal();
    Animal(Animal const& instance);
    virtual ~Animal();

    Animal& operator=(Animal const& rhs);

    std::string     getType() const;
    virtual void    makeSound() const;
protected:
    std::string m_type;
};

#endif
