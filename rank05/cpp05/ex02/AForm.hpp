#ifndef AFORM_H
#define AFORM_H

#include <exception>
#include <string>

#include "Bureaucrat.hpp"

class AForm {
   public:
    AForm();
    AForm(std::string name, std::string target, int grade, int exec);
    AForm(AForm const &instance);
    virtual ~AForm();

    AForm &operator=(AForm const &rhs);

    std::string getName() const;
    std::string getTarget() const;
    int getRequiredGrade() const;
    int getRequiredGradeToExecute() const;
    bool isSigned() const;
    void beSigned(Bureaucrat const &bureaucrat);
    virtual void execute(Bureaucrat const &executor) const;

    class GradeTooHighException : public std::exception {
       public:
        virtual char const *what() const throw();
    };
    class GradeTooLowException : public std::exception {
       public:
        virtual char const *what() const throw();
    };
    class AFormSignedException : public std::exception {
       public:
        virtual char const *what() const throw();
    };
    class AFormNotSignedException : public std::exception {
       public:
        virtual char const *what() const throw();
    };

   private:
    std::string const m_name;
    std::string const m_target;
    bool m_signed;
    int const m_requiredGrade;
    int const m_requiredGradeToExecute;
};

std::ostream &operator<<(std::ostream &o, AForm const &instance);

#endif
