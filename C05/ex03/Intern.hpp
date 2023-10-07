#ifndef DEF_INTERN_HPP
#define DEF_INTERN_HPP

#include "AForm.hpp"

class Intern
{
public:
    AForm* makeForm(const std::string& formName, const std::string& target);

private:
    std::string target;
};
#endif