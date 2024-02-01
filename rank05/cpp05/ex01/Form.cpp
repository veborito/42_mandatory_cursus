#include "Form.hpp"

#include <iostream>
#include <string>

Form::Form() : m_name("default"), m_signed(false), m_requiredGrade(150) {}
Form::Form(std::string name, int grade)
    : m_name(name), m_signed(false), m_requiredGrade(grade) {
    if (grade < 1) throw Form::GradeTooHighException();
    if (grade > 150) throw Form::GradeTooLowException();
}
Form::Form(Form const &instance)
    : m_name(instance.getName()),
      m_signed(instance.isSigned()),
      m_requiredGrade(instance.m_requiredGrade) {
    *this = instance;
}
Form::~Form() {}

Form &Form::operator=(Form const &rhs) {
    (void)rhs;
    return *this;
}

std::string Form::getName() const { return this->m_name; }
int Form::getRequiredGrade() const { return this->m_requiredGrade; }
bool Form::isSigned() const { return this->m_signed; }
void Form::beSigned(Bureaucrat const &bureaucrat) {
    if (this->m_signed)
        throw Form::FormSignedException();
    else if (bureaucrat.getGrade() > this->m_requiredGrade)
        throw Form::GradeTooLowException();
    else
        this->m_signed = true;
}

char const *Form::GradeTooHighException::what() const throw() {
    return "Grade too high !";
}
char const *Form::GradeTooLowException::what() const throw() {
    return "Grade too low !";
}
char const *Form::FormSignedException::what() const throw() {
    return "Already signed !";
}

std::ostream &operator<<(std::ostream &o, Form const &instance) {
    if (instance.isSigned()) {
        o << instance.getName() + ", Form required grade " +
                 std::to_string(instance.getRequiredGrade()) + " and is signed";
        return o;
    }
    o << instance.getName() + ", Form required grade " +
             std::to_string(instance.getRequiredGrade()) + " and is not signed";
    return o;
}
