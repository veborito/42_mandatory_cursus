#ifndef CAT_H
#define CAT_H
#include "Animal.hpp"

class Cat : public Animal {
public:
    Cat();
    Cat(Cat const& instance);
    ~Cat();

    Cat& operator=(Cat const& rhs);

    void        makeSound() const;
};

#endif
