#include "ClapTrap.hpp"
#include <iostream>
#include <string>

int main() {
    ClapTrap trap;
    ClapTrap traposor("Traposor");
    ClapTrap trapCopy(traposor);
    ClapTrap trapi("trapi");

    std::cout << trap << '\n' << traposor << '\n' << trapCopy << '\n' << trapi
              << "\n";
    std::cout << "--------------------\n";
    trapi.attack("Un mec");
    trapi.takeDamage(5);
    trapi.beRepaired(1);
    trap = trapi;
    std::cout << trap << '\n' << traposor << '\n' << trapCopy << '\n' << trapi
              << "\n";
    return 0;
}
