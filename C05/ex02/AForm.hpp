#ifndef AForm_HPP
#define AForm_HPP

#include "Bureaucrat.hpp"

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <string>
class Bureaucrat;

class AForm
{
public:
    AForm();
    ~AForm();
    AForm(const AForm& src);
    AForm &operator=(const AForm &src);
    AForm(const std::string &name, int gradeSign, int gradeExecute);

    const std::string &getName() const;
    int getGradeSign() const;
    int getGradeExecute() const;
    bool isSigned() const;
    bool get_Grade_bool_sign() const;
    // void executeAction();
    virtual void execute(Bureaucrat const &executor) const = 0;
    virtual void executeAction() const ;

    void beSigned(const Bureaucrat& bureaucrat);

    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return "Grade is too high";
        }
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return "Grade is too low";
        }
    };
    class FormNotSignedException : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return "Form is not signed";
        }
    };

private:
    const std::string name;
    bool sign;
    const int gradeSign;
    const int gradeExecute;
};

std::ostream &operator<<(std::ostream &os, const AForm &AForm);

#endif