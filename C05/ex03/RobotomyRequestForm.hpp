#ifndef DEF_ROBOTOMYREQUESTFORM
#define DEF_ROBOTOMYREQUESTFORM

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm(const std::string &target);
	void beSigned(const Bureaucrat &bureaucrat) const;
	virtual void execute(Bureaucrat const &executor) const;
	 RobotomyRequestForm(const RobotomyRequestForm &src); 
    RobotomyRequestForm & operator=(const RobotomyRequestForm &rhs);
    ~RobotomyRequestForm();
	RobotomyRequestForm();
	class RobotomyRequestFormGradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "RobotomyRequestForm grade is too high";
		}
	};

	class RobotomyRequestFormGradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "RobotomyRequestForm grade is too low";
		}
	};
	class NotSignedException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "RobotomyRequestForm is not Signed";
		}
	};
	std::string getTarget() const;

private:
	std::string target;
};
#endif