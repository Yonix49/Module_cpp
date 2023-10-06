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
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <iostream>

int main()
{

	std::cout << "--------DAVID----------" << std::endl;
	try{
		Bureaucrat	david("david", 50);
		Form		f1("f1", 70, 70);
		Form		f2("f2", 20, 20);
		std::cout << david << f1 << f2;
		david.signForm(f1);
		david.signForm(f2);
		std::cout << f1 << f2;
		f1 = f2;
		std::cout << f1 << f2;
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	return 0;
};