#include "utils.hpp"
#include "Zombie.hpp"

int main() {
    Zombie* karl = newZombie("Karl");
    karl->annonce();
    delete karl;
    randomChump("Joe");
    return 0;
}
