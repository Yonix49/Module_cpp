#ifndef DEF_SHRUBBERYCREATIONFORM
#define DEF_SHRUBBERYCREATIONFORM

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
public:

    ~ShrubberyCreationForm();
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &src); 
    ShrubberyCreationForm & operator=(const ShrubberyCreationForm &rhs);
	
	
	ShrubberyCreationForm(const std::string &target);
	virtual void execute(Bureaucrat const &executor) const;
	std::string getTarget() const;
	
	
	class ShrubberyCreationGradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "ShrubberyCreationForm grade is too high";
		}
	};

	class ShrubberyCreationGradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "ShrubberyCreationForm grade is too low";
		}
	};
	class NotSignedException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "ShrubberyCreationForm is not Signed";
		}
	};
	class ErrorOpen : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "Error while open";
		}
	};


private:
	std::string target;
};

#endif