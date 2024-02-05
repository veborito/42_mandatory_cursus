#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

#include "AForm.hpp"

class Intern {
   public:
    Intern();
    Intern(Intern const &instance);
    ~Intern();

    Intern &operator=(Intern const &rhs);

    AForm *makeForm(std::string form, std::string target) const;
};

std::ostream &operator<<(std::ostream &o, Intern const &instance);

#endif
