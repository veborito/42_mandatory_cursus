#include "utils.hpp"
#include "Zombie.hpp"

int main() {
    Zombie* karl = newZombie("Karl");
    randomChump("Joe");
    delete karl;
    return 0;
}
