#ifndef DEF_PRESIDENTIALPARDONFORM
#define DEF_PRESIDENTIALPARDONFORM

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
    PresidentialPardonForm(const PresidentialPardonForm &src); 
    PresidentialPardonForm & operator=(const PresidentialPardonForm &rhs);
    ~PresidentialPardonForm();
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string &target);
    void beSigned(const Bureaucrat &bureaucrat) const;
    virtual void execute(Bureaucrat const &executor) const;

    // virtual void executeAction(const Bureaucrat &bureaucrat) const;

    class PresidentialPardonFormGradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return "PresidentialPardonForm grade is too high";
        }
    };

    class PresidentialPardonFormGradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return "PresidentialPardonForm grade is too low";
        }
    };
    class NotSignedException : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return "PresidentialPardonForm is not Signed";
        }
    };
    std::string getTarget() const;

private:
    std::string target;
};
#endif