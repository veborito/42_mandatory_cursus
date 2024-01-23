#ifndef CAT_H
#define CAT_H
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
public:
    Cat();
    Cat(Cat const& instance);
    ~Cat();

    Cat& operator=(Cat const& rhs);

    Brain*      getBrain() const;
    void        makeSound() const;
private:
    Brain*      m_brain; 
};

#endif
