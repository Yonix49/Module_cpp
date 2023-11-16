/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 17:10:49 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/10/12 16:21:07 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <iostream>
#include <string>
#include <limits.h>
#include <iomanip>
#include <cmath>
ScalarConverter::~ScalarConverter()
{
}

// Constructeur
ScalarConverter::ScalarConverter()
{
}
// Constructeur de copie
ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	(void)(src);
}
bool ScalarConverter::isChar(std::string str)
{
	return (str.length() == 1 && std::isprint(str[0]) && std::isalpha(str[0]));
	//Char imprimable et lettre alphabetique
};


bool ScalarConverter::isInt(std::string str)
{
	char *endptr = NULL;

	std::strtol(str.c_str(), &endptr, 10);
	//Converti chaine en entier exp = "1232"
	return (endptr == &str[0] + str.length());//Verification si la conversion est correcte 
};

bool ScalarConverter::isFloat(std::string str)
{
	char *endptr = NULL;

	std::strtof(str.c_str(), &endptr);
	return (*endptr == 'f' && (endptr == &str[0] + str.length()) + 1);
};

bool ScalarConverter::isDouble(std::string str)
{
	char *endptr = NULL;

	std::strtod(str.c_str(), &endptr);
	return (endptr == &str[0] + str.length());
};

void ScalarConverter::Convert(std::string str)
{
	if (isChar(str))
		printChar(str[0]);
	else if (isInt(str))
		printInt(std::atol(str.c_str()));
	else if (isFloat(str))
		printFloat(std::strtof(str.c_str(), NULL));
	else if (isDouble(str))
		printDouble(std::strtod(str.c_str(), NULL));
	else
		std::cout << "Unknow type" << std::endl;
}

void ScalarConverter::printChar(char c)
{
	if (std::isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << c << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

void ScalarConverter::printInt(long n)
{
	char c = static_cast<char>(n);
	if (n < CHAR_MIN || n > CHAR_MAX || n < static_cast<int>(INT_MIN) || n > static_cast<int>(INT_MAX) )
    	std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(c))
    	std::cout << "char: Non displayable" << std::endl;
	else
    	std::cout << "char: '" << c << "'" << std::endl;


	
	if (n < INT_MIN || n > INT_MAX || std::isnan(n) || std::isinf(n))
		std::cout << "int: impossible" << std::endl;
	else 
		std::cout << "int: " << static_cast<int>(n) << std::endl;
	
	if (n - static_cast<int>(n) == 0)
		std::cout << "float: " << n << ".0" << "f" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(n) << "f" << std::endl;

	
	if (n - static_cast<int>(n) == 0)
		std::cout << "double: " << n << ".0" << std::endl;
	else
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(n) << std::endl;
}

void ScalarConverter::printFloat(float f)
{
	char c = static_cast<char>(f);
	if (f < CHAR_MIN || f > CHAR_MAX  || std::isnan(f) || std::isinf(f))
    	std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(c))
    	std::cout << "char: Non displayable" << std::endl;
	else
    	std::cout << "char: '" << c << "'" << std::endl;
	

	if (f < static_cast<float>(INT_MIN) || f > static_cast<float>(INT_MAX) || std::isnan(f) || std::isinf(f))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	// std::cout << "float: " << f << "f" << std::endl;
	if (f - static_cast<int>(f) == 0)
		std::cout << "float: " << f << ".0" << "f"<< std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;
	if (f - static_cast<int>(f) == 0)
		std::cout << "double: " << f << ".0" << std::endl;
	else
		std::cout << "double: " << f << std::endl;
}

void ScalarConverter::printDouble(double d)
{
	char c = static_cast<char>(d);
	if (d < CHAR_MIN || d > CHAR_MAX || d < INT_MIN || d > INT_MAX )
    	std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(c))
    	std::cout << "char: impossible" << std::endl;
	else
	{
    	std::cout << "char: '" << c << "'" << std::endl;
	}
	
	if (d < INT_MIN || d > INT_MAX || std::isnan(d) || std::isinf(d))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	// std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(d) << std::endl;
	// std::cout << "float: " << std::scientific << std::setprecision(1) << d << "f" << std::endl;
	if (d - static_cast<int>(d) == 0)
		std::cout << "double: " << d << ".0" << std::endl;
	else
		std::cout << "double: " << d << std::endl;

}