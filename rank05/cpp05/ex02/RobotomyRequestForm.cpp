#include "RobotomyRequestForm.hpp"

#include <string>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", "default", 72, 45) {}
RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("RobotomyRequestForm", target, 72, 45) {}
RobotomyRequestForm::RobotomyRequestForm(
    RobotomyRequestForm const &instance)
    : AForm(instance) {
    *this = instance;
}
RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(
    RobotomyRequestForm const &rhs) {
    (void)rhs;
    return *this;
}


void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    AForm::execute(executor);
    std::cout << "* SOME DRILLING NOISE...BBRRTTRRCRACKCRICK *\n";
    std::srand(std::time(0));
    int random = std::rand();
    if (random % 2 == 0)
        std::cout << this->getTarget() << " has been robotomized !\n";
    else
        std::cout << "Robotomy failed\n";
}
