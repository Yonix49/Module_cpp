/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:05:36 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/10/07 19:16:04 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("Shrubbery Creation", 25, 5), target(target)
{
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