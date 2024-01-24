#include "utils.hpp"
#include "Zombie.hpp"
#include <iostream>

int main() {
    Zombie* karl = newZombie("Karl");
    karl->annonce();
    delete karl;
    std::cout << "avant la fonction\n";
    randomChump("Joe");
    std::cout << "apres la fonction\n";
    return 0;
}
