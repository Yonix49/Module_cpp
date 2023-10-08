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
#include "Intern.hpp"
int main()
{
    try {
        Bureaucrat david("david", 1);
        Intern someRandomIntern;
        AForm* rrf;

        rrf = someRandomIntern.makeForm("Momo request", "Bender");

        if (rrf != NULL) {
            david.signForm(*rrf);
            delete rrf;
        }
        else {
            std::cout << "Cannot sign a NULL form." << std::endl;
        }

        rrf = someRandomIntern.makeForm(" request", "Bender");

        if (rrf != NULL) {
            david.signForm(*rrf);
            delete rrf;
        }
        else {
            std::cout << "Cannot sign a NULL form." << std::endl;
        }
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}

