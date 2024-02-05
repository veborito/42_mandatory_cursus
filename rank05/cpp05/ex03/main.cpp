#include <iostream>
#include <string>

#include "Intern.hpp"
#include "AForm.hpp"

int main() {
    Intern someRandomIntern;
    AForm* rrf;
    AForm* scf;
    std::cout << someRandomIntern << '\n';
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    scf = someRandomIntern.makeForm("false", "Boris");

    (void)rrf;
    (void)scf;

    return 0;
}
