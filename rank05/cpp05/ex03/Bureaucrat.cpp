#include "Bureaucrat.hpp"

#include <exception>
#include <iostream>
#include <string>

#include "AForm.hpp"

Bureaucrat::Bureaucrat() : m_name("default"), m_grade(150) {}
Bureaucrat::Bureaucrat(std::string name, int grade) : m_name(name) {
    if (grade < 1) throw Bureaucrat::GradeTooHighException();
    if (grade > 150) throw Bureaucrat::GradeTooLowException();
    this->m_grade = grade;
}
Bureaucrat::Bureaucrat(Bureaucrat const &instance)
    : m_name(instance.getName()), m_grade(instance.getGrade()) {
    *this = instance;
}
Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs) { 
    (void)rhs;
    return *this;
}

std::string Bureaucrat::getName() const { return this->m_name; }
int Bureaucrat::getGrade() const { return this->m_grade; }

void Bureaucrat::incrementGrade() {
    if ((this->m_grade - 1) < 1) throw Bureaucrat::GradeTooHighException();
    this->m_grade--;
}
void Bureaucrat::decrementGrade() {
    if ((this->m_grade + 1) > 150) throw Bureaucrat::GradeTooLowException();
    this->m_grade++;
}
void Bureaucrat::signForm(AForm &form) const {
    try {
        form.beSigned(*this);
        std::cout << this->m_name << " signed " << form.getName() << '\n';
    } catch (std::exception &e) {
        std::cerr << this->m_name << " couldn't sign " << form.getName()
                  << " because " << e.what() << '\n';
    }
}

void Bureaucrat::executeForm(AForm const &form) const {
    try {
        form.execute(*this);
        std::cout << this->m_name << " executed " << form.getName() << '\n';
    } catch (std::exception &e) {
        std::cerr << this->m_name << " couldn't execute " << form.getName()
                  << " because " << e.what() << '\n';
    }
}

char const *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high !\n";
}

char const *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low !\n";
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &instance) {
    o << instance.getName() + ", bureaucrat grade " +
             std::to_string(instance.getGrade());
    return o;
}
