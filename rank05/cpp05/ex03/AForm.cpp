#include "AForm.hpp"

#include <iostream>
#include <string>

AForm::AForm()
    : m_name("default"),
      m_target("default"),
      m_signed(false),
      m_requiredGrade(150),
      m_requiredGradeToExecute(0) {}
AForm::AForm(std::string name, std::string target, int grade, int exec)
    : m_name(name),
      m_target(target),
      m_signed(false),
      m_requiredGrade(grade),
      m_requiredGradeToExecute(exec) {
    if (grade < 1) throw AForm::GradeTooHighException();
    if (grade > 150) throw AForm::GradeTooLowException();
}
AForm::AForm(AForm const &instance)
    : m_name(instance.getName()),
      m_target(instance.m_target),
      m_signed(instance.isSigned()),
      m_requiredGrade(instance.m_requiredGrade),
      m_requiredGradeToExecute(instance.m_requiredGradeToExecute) {
    if (this != &instance)
        *this = instance;
}
AForm::~AForm() {}

AForm &AForm::operator=(AForm const &rhs) {
    (void)rhs;
    return *this;
}

std::string AForm::getName() const { return this->m_name; }
std::string AForm::getTarget() const { return this->m_target; }
int AForm::getRequiredGrade() const { return this->m_requiredGrade; }
int AForm::getRequiredGradeToExecute() const {
    return this->m_requiredGradeToExecute;
}
bool AForm::isSigned() const { return this->m_signed; }
void AForm::beSigned(Bureaucrat const &bureaucrat) {
    if (this->m_signed)
        throw AForm::AFormSignedException();
    else if (bureaucrat.getGrade() > this->m_requiredGrade)
        throw AForm::GradeTooLowException();
    else
        this->m_signed = true;
}
void AForm::execute(Bureaucrat const &executor) const {
    if(!this->isSigned())
        throw AForm::AFormNotSignedException();
    else if (executor.getGrade() > this->getRequiredGradeToExecute())
        throw AForm::GradeTooLowException();
}

char const *AForm::GradeTooHighException::what() const throw() {
    return "Grade too high !";
}
char const *AForm::GradeTooLowException::what() const throw() {
    return "Grade too low !";
}
char const *AForm::AFormSignedException::what() const throw() {
    return "Form already signed !";
}
char const *AForm::AFormNotSignedException::what() const throw() {
    return "Form not signed !";
}

std::ostream &operator<<(std::ostream &o, AForm const &instance) {
    if (instance.isSigned()) {
        o << instance.getName() + ", form required grade " +
                 std::to_string(instance.getRequiredGrade()) +
                 ", required grade to execute " +
                 std::to_string(instance.getRequiredGradeToExecute()) +
                 ", target " + instance.getTarget() + " and is signed";
        return o;
    }
    o << instance.getName() + ", form required grade " +
             std::to_string(instance.getRequiredGrade()) +
             ", required grade to execute " +
             std::to_string(instance.getRequiredGradeToExecute()) + ", target " +
             instance.getTarget() + " and is not signed";
    return o;
}
