#include "Zombie.hpp"
#include <string>
#include <iostream>

Zombie* zombieHorde(int N, std::string name);

int main() {
    int size = 10;
    Zombie* horde = zombieHorde(size, "karl");
    for (int i = 0; i < size; ++i) {
        std::cout << i + 1 << ". " ;
        horde[i].annonce();
    }
    delete [] horde;
    return 0;
}
