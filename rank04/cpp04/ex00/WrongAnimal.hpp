#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H
#include <string>

class WrongAnimal {
public:
    WrongAnimal();
    WrongAnimal(WrongAnimal const& instance);
    virtual ~WrongAnimal(); // si pas de virtual possible memory leak

    WrongAnimal& operator=(WrongAnimal const& rhs);

    std::string     getType() const;
    void    makeSound() const;
protected:
    std::string m_type;
};

#endif
