#include "Intern.hpp"

#include <iostream>
#include <string>

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(){};
Intern::Intern(Intern const &instance) { *this = instance; }
Intern::~Intern() {}

Intern &Intern::operator=(Intern const &rhs) {
    (void)rhs;
    return *this;
}

AForm *Intern::makeForm(std::string form, std::string target) const {
    std::string formsTab[4] = {"robotomy request", "shrubbery creation",
                               "presidential pardon"};
    int formID = -1;
    for (int i = 0; i < 4; ++i) {
        if (formsTab[i] == form) {
            formID = i;
            break;
        }
    }
    switch (formID) {
        case 0:
            return new RobotomyRequestForm(target);
        case 1:
            return new ShrubberyCreationForm(target);
        case 2:
            return new PresidentialPardonForm(target);
    }
    std::cerr << form
              << " doesn't exist. The intern couldn't create it and now he's "
                 "panicking\n";
    return nullptr;
}

std::ostream &operator<<(std::ostream &o, Intern const &instance) {
    (void)instance;
    o << "Just an intern nobody cares.";
    return o;
}
