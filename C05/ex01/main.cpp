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
#include "Form.hpp"

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <iostream>

int main()
{

	std::cout << "--------Momo----------" << std::endl;
	try
	{
		Bureaucrat Momo("Momo", 50);
		Form Alt1("Alt1", 70, 70);
		Form Alt2("Alt2", 20, 20);
		std::cout << Momo << Alt1 << Alt2;
		Momo.signForm(Alt1);
		Momo.signForm(Alt2);
		std::cout << Alt1 << Alt2 << std::endl;
		Alt1 = Alt2;
		std::cout << Alt1 << Alt2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
};