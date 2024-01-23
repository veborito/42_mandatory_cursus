#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main() {
    AAnimal* animaux[10];

    for(int i = 0; i < 10; ++i) {
        if (i < 5)
            animaux[i] = new Cat();
        else
            animaux[i] = new Dog();
    }
    for(int i = 0; i < 10; ++i)
        delete animaux[i]; 

    Brain* brain = new Brain();
    Brain* brain2 = new Brain();

    brain->setIdea("Boris", 0);
    *brain2 = *brain;
    std::cout << brain->getIdeas()[0] << '\n';
    std::cout << brain2->getIdeas()[0] << '\n';
    brain->setIdea("Carmelle", 0);
    std::cout << brain->getIdeas()[0] << '\n';
    std::cout << brain2->getIdeas()[0] << '\n';
    delete brain;
    delete brain2;

    std::cout << "------- AUTRE --------\n";
    Cat* cat = new Cat(); 
    Cat* otherCat = new Cat();

    cat->getBrain()->setIdea("Boris", 0);
    *otherCat = *cat;
    std::cout << cat->getBrain()->getIdeas()[0] << '\n';
    std::cout << otherCat->getBrain()->getIdeas()[0] << '\n';

    otherCat->getBrain()->setIdea("Carmelle", 0);
    std::cout << cat->getBrain()->getIdeas()[0] << '\n';
    std::cout << otherCat->getBrain()->getIdeas()[0] << '\n';
    delete cat;
    delete otherCat;
    
    //std::scout << "Ne marche pas\n";
    //AAnimal* animal = new AAnimal();
    return 0;
}
