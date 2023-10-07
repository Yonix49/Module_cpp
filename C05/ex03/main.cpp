/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 09:37:46 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/10/06 09:37:46 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{

	try{
		std::cout << "--------ShrubberyCreationForm----------" << std::endl;
		Bureaucrat	Momo("Momo", 1);
		Bureaucrat	ZongoLeDozo("ZongoLeDozo", 150);
		ShrubberyCreationForm f1("tree");
		std::cout << Momo << ZongoLeDozo << f1 << std::endl;

		Momo.executeForm(f1);
		ZongoLeDozo.executeForm(f1);
		ZongoLeDozo.signForm(f1);
		Momo.signForm(f1);
		ZongoLeDozo.executeForm(f1);
		Momo.executeForm(f1);
		std::cout << f1 << std::endl;

		std::cout << "--------RobotomyRequestForm---------" << std::endl;
		RobotomyRequestForm f2("frank");
		Momo.executeForm(f2);
		ZongoLeDozo.executeForm(f2);
		ZongoLeDozo.signForm(f2);
		Momo.signForm(f2);
		ZongoLeDozo.executeForm(f2);
		Momo.executeForm(f2);
		Momo.executeForm(f2);
		Momo.executeForm(f2);
		Momo.executeForm(f2);

		std::cout << std::endl << "--------PresidentialPardonForm--------" << std::endl;
		PresidentialPardonForm f3("eden");
		Momo.executeForm(f3);
		ZongoLeDozo.executeForm(f3);
		ZongoLeDozo.signForm(f3);
		Momo.signForm(f3);
		ZongoLeDozo.executeForm(f3);
		Momo.executeForm(f3);
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	return 0;
};

