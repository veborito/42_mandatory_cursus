#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main() {
    std::cout << "DEFAULT TESTS\n";
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;
    
    std::cout << "-------- MES TESTS -------\n";

    WrongAnimal const* wrongAnimal = new WrongAnimal();
    WrongAnimal const* wrongCat = new WrongCat();

    std::cout << wrongAnimal->getType() << '\n';
    std::cout << wrongCat->getType() << '\n';

    wrongCat->makeSound();
    wrongAnimal->makeSound();

    delete wrongAnimal;
    delete wrongCat;
     
    std::cout << "-------- NOUVEAU TESTS -------\n";

    Animal* animaux[10];

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
    return 0;
}
