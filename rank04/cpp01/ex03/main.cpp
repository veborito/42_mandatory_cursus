#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main() {
    {
        Weapon club;

        club.setType("club");
        HumanA bob("bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club;

        club.setType("club");
        HumanB carl("carl");
        carl.setWeapon(&club);
        carl.attack();
        club.setType("some other type of club");
        carl.attack();
    }
    return 0;
}
