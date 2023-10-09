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
	std::cout << "--------Momo----------" << std::endl;
	try{
		Bureaucrat Momo("Momo", 1);
		std::cout << Momo;
		while (Momo.getGrade() < 150)
			Momo.GradeDecrement();
		std::cout << Momo;
		while (Momo.getGrade() > 1)
			Momo.GradeDecrement();
		std::cout << Momo;
		Momo.GradeIncrement();
		std::cout << Momo;
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "--------Yoyo----------" << std::endl;
	try{
		Bureaucrat Yoyo("Yoyo", 0);
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try{
		Bureaucrat Yoyo("Yoyo", 151);
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "--------COMPARE----------" << std::endl;
	try{
		Bureaucrat Momo("Momo", 1);
		Bureaucrat Yoyo("Yoyo", 150);
		Bureaucrat Yummi(Momo);

		std::cout << Momo << Yoyo << "Yummi: " << Yummi;
		Momo = Yoyo; 
		std::cout << Momo << Yoyo << "Yummi: " << Yummi;
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	return 0;
};