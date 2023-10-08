/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 20:35:51 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/10/08 12:06:36 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Intern.hpp"

Intern::Intern()
{
	
}
Intern::~Intern()
{
	
}
Intern::Intern(const Intern &)
{
	
}
Intern & Intern::operator= (const Intern &) 
{ 
	return *this;
}
AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    std::string word[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm* forms[] = {
        new ShrubberyCreationForm(target),
        new RobotomyRequestForm(target),
        new PresidentialPardonForm(target),
    };
    AForm* result = NULL;

    for (int i = 0; i < 3; i++)
    {
        if (word[i].compare(formName) == 0)
        {
            std::cout << "Intern creates " << formName << " Form" << std::endl;
            result = forms[i];
        }
        else
        {
            delete forms[i];
        }
    }

    if (not result)
    {
        std::cout << "Intern cannot create " << formName << " form" << std::endl;
    }

    return result;
}

