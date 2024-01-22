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

    return 0;
}
