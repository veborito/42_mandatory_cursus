#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include <string>

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm {
   public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(PresidentialPardonForm const &instance);
    virtual ~PresidentialPardonForm();

    PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);

    virtual void execute(Bureaucrat const &executor) const;
};

#endif
