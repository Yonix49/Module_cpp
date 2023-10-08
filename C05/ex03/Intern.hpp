#ifndef DEF_INTERN_HPP
#define DEF_INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public:
    Intern();
    Intern(const Intern &);
    ~Intern();
    Intern &operator=(const Intern &);

    AForm* makeForm(const std::string& formName, const std::string& target);

};
#endif