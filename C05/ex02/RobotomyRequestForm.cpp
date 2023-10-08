/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:05:43 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/10/08 13:04:17 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequestForm Creation", 72, 5), target(target)
{

}
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 5), target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src.getName(), src.getGradeSign(), src.getGradeExecute()) 
{
	*this = src;
}
RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm & RobotomyRequestForm::operator= (const RobotomyRequestForm &rhs) 
{
	if (this != &rhs)
	{
		target = rhs.target;
	}
	return *this;
}
void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (isSigned() == false)
		throw NotSignedException();
	else if (executor.getGrade() > getGradeExecute())
		throw GradeTooLowException();
    std::cout << "Bzzz... Making drilling noises..." << std::endl;
    int randomValue = rand();
    if (randomValue <= RAND_MAX / 2)
    {
        std::cout << getTarget() << " has been robotomized successfully!" << std::endl;
    }
    else
    {
        std::cout << "Robotomy of " << getTarget() << " failed." << std::endl;
    }
}
std::string RobotomyRequestForm::getTarget() const
{
    return target ;
}

