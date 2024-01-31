#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <string>

class Bureaucrat {
   public:
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(Bureaucrat const &instance);
    ~Bureaucrat();

    Bureaucrat &operator=(Bureaucrat const &rhs);

    std::string const getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();

    class GradeTooHighException : public std::exception {
       public:
        virtual char const *what() const throw();
    };

    class GradeTooLowException : public std::exception {
       public:
        virtual char const *what() const throw();
    };

   private:
    std::string const m_name;
    int m_grade;
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &instance);

#endif
