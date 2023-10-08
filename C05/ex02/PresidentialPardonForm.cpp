/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:05:36 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/10/08 13:16:47 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("Shrubbery Creation", 25, 5), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("default") {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src.getName(), src.getGradeSign(), src.getGradeExecute()) 
{
	*this = src;
}

PresidentialPardonForm & PresidentialPardonForm::operator= (const PresidentialPardonForm &rhs) 
{
	if (this != &rhs)
	{
		target = rhs.target;
	}
	return *this;
}
void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (isSigned() == false)
		throw NotSignedException();
	else if (executor.getGrade() <= getGradeSign())
	{
		std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
	else
	{
		throw PresidentialPardonFormGradeTooHighException();
	}
}

std::string PresidentialPardonForm::getTarget() const
{
	return target;
}