#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>

class AAnimal {
public:
    AAnimal();
    AAnimal(AAnimal const& instance);
    virtual ~AAnimal();

    AAnimal& operator=(AAnimal const& rhs);

    std::string     getType() const;
    virtual void    makeSound() const = 0;
protected:
    std::string m_type;
};

#endif
