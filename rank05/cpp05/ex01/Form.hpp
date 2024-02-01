#ifndef FORM_H
#define FORM_H

#include <exception>
#include <string>

#include "Bureaucrat.hpp"

class Form {
   public:
    Form();
    Form(std::string name, int grade);
    Form(Form const &instance);
    ~Form();

    Form &operator=(Form const &rhs);

    std::string getName() const;
    int getRequiredGrade() const;
    bool isSigned() const;
    void beSigned(Bureaucrat const &bureaucrat);

    class GradeTooHighException : public std::exception {
       public:
        virtual char const *what() const throw();
    };
    class GradeTooLowException : public std::exception {
       public:
        virtual char const *what() const throw();
    };
    class FormSignedException : public std::exception {
       public:
        virtual char const *what() const throw();
    };

   private:
    std::string const m_name;
    bool m_signed;
    int const m_requiredGrade;
};

std::ostream &operator<<(std::ostream &o, Form const &instance);

#endif
