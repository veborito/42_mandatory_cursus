#include "ShrubberyCreationForm.hpp"

#include <fstream>
#include <iostream>
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", "default", 145, 137) {}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreationForm", target, 145, 137) {}
ShrubberyCreationForm::ShrubberyCreationForm(
    ShrubberyCreationForm const &instance)
    : AForm(instance) {
    *this = instance;
}
ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(
    ShrubberyCreationForm const &rhs) {
    (void)rhs;
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    AForm::execute(executor);
    std::ofstream ofs(this->getTarget() + "_shruberry");
    if (!ofs.is_open()) {
        std::cerr << "File cannot be open !\n";
        exit(1);
    }
    ofs << "             ,@@@@@@@,"
        << "                                    ,@@@@@@@,\n"
        << "     ,,,.   ,@@@@@@/@@,  .oo8888o."
        << "                ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
        << " ,&%%&%&&%,@@@@@/@@@@@@,8888'888/8o"
        << "          ,&%%&%&&%,@@@@@/@@@@@@,8888'888/8o\n"
        << " ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'"
        << "         ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
        << " %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'"
        << "         %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
        << " %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'"
        << "          %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
        << " &%k\\ ` /%&'    |.|        \\ '|8'"
        << "            &%k\\ ` /%&'    |.|        \\ '|8'\n"
        << "     |o|        | |         | |"
        << "                  |o|        | |         | |\n"
        << "     |.|        | |         | |"
        << "                  |.|        | |         | |\n"
        << "   \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_"
        << "         \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n";
    ofs.close();
}
