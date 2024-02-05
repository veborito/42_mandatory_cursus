#include <iostream>
#include <string>

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {
    Bureaucrat boris("Boris", 1);
    Bureaucrat carmelle("Carmelle", 150);
    Bureaucrat mily("Mily", 10);
    Bureaucrat malia(mily);

    ShrubberyCreationForm f1("home");
    RobotomyRequestForm f2("Carmelle");
    PresidentialPardonForm f3("Malia");

    std::cout << "--- FORMS ---\n";
    std::cout << f1 << '\n';
    std::cout << f2 << '\n';
    std::cout << f2 << '\n';
    std::cout << "-------------\n";
    carmelle.signForm(f1);
    boris.executeForm(f1);
    boris.signForm(f1);
    boris.executeForm(f1);
    malia.signForm(f2);
    malia.executeForm(f2);
    mily.signForm(f3);
    mily.executeForm(f3);
    boris.executeForm(f3);
    return 0;
}
