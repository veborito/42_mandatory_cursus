#ifndef ROBOTOMYREQUESTFORM_H 
#define ROBOTOMYREQUESTFORM_H 

#include <string>

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm {
   public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(RobotomyRequestForm const &instance);
    virtual ~RobotomyRequestForm();

    RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);

    virtual void execute(Bureaucrat const &executor) const;
};

#endif
