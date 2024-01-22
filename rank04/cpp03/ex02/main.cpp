#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
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
    std::cout << "--------------------\n";
    ScavTrap strap;
    ScavTrap straposor("sTraposor");
    ScavTrap strapCopy(straposor);
    ScavTrap strapi("strapi");

    std::cout << strap << '\n' << straposor << '\n' << strapCopy << '\n'
              << strapi << "\n";
    std::cout << "--------------------\n";
    strapi.attack("Un autre mec");
    strapi.takeDamage(50);
    strapi.beRepaired(10);
    strap = strapi;
    straposor.guardGate();
    std::cout << strap << '\n' << straposor << '\n' << strapCopy << '\n'
              << strapi << "\n";
    std::cout << "--------------------\n";
    FragTrap ftrap;
    FragTrap ftraposor("fTraposor");
    FragTrap ftrapCopy(ftraposor);
    FragTrap ftrapi("ftrapi");

    std::cout << ftrap << '\n' << ftraposor << '\n' << ftrapCopy << '\n'
              << ftrapi << "\n";
    std::cout << "--------------------\n";
    ftrapi.attack("Encore un autre mec");
    ftrapi.takeDamage(70);
    ftrapi.beRepaired(20);
    ftrapi.takeDamage(100);
    ftrapi.beRepaired(20);
    ftrap = ftrapi;
    ftraposor.highFivesGuys();
    std::cout << ftrap << '\n' << ftraposor << '\n' << ftrapCopy << '\n'
              << ftrapi << "\n";
    return 0;
}
