#include "PresidentialPardonForm.hpp"

#include <iostream>
#include <string>

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", "default", 25, 5) {}
PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("PresidentialPardonForm", target, 25, 5) {}
PresidentialPardonForm::PresidentialPardonForm(
    PresidentialPardonForm const &instance)
    : AForm(instance) {
    *this = instance;
}
PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(
    PresidentialPardonForm const &rhs) {
    (void)rhs;
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    AForm::execute(executor);
    std::cout << this->getTarget()
              << " has been pardoned by Zaphod Beeblebrox.\n";
}
