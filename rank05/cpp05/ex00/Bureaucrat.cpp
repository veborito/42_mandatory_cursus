#include "Bureaucrat.hpp"

#include <string>
#include <iostream>

Bureaucrat::Bureaucrat() : m_name("default"), m_grade(150) {}
Bureaucrat::Bureaucrat(std::string name, int grade) : m_name(name) {
    if (grade < 1) throw Bureaucrat::GradeTooHighException();
    if (grade > 150) throw Bureaucrat::GradeTooLowException();
    this->m_grade = grade;
}
Bureaucrat::Bureaucrat(Bureaucrat const &instance) { *this = instance; }
Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs) {
    this->m_grade = rhs.getGrade();
    return *this;
}

std::string const Bureaucrat::getName() const { return this->m_name; }
int Bureaucrat::getGrade() const { return this->m_grade; }

void Bureaucrat::incrementGrade() {
    if ((this->m_grade - 1) < 1) throw Bureaucrat::GradeTooHighException();
    this->m_grade--;
}
void Bureaucrat::decrementGrade() {
    if ((this->m_grade + 1) > 150) throw Bureaucrat::GradeTooLowException();
    this->m_grade++;
}

char const *Bureaucrat::GradeTooHighException::what() const throw() {
    return "The grade of the bureaucrat is to high !\n";
}

char const *Bureaucrat::GradeTooLowException::what() const throw() {
    return "The grade of the bureaucrat is to low !\n";
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &instance) {
    o << instance.getName() + ", bureaucrat grade " +
             std::to_string(instance.getGrade()); 
    return o;
}
