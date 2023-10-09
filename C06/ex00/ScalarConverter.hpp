/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 17:09:46 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/10/09 18:29:04 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cctype> // Pour isprint

class ScalarConverter
{
public:
	~ScalarConverter();
	static void Convert(std::string str);

	static bool isChar(std::string str);
	static bool isInt(std::string str);
	static bool isFloat(std::string str);
	static bool isDouble(std::string str);
	static bool isLitteral(std::string str);

	static void printChar(char c);
	static void printInt(long n);
	static void printFloat(float f);
	static void printDouble(double d);

	



	private:
	ScalarConverter();
	ScalarConverter &operator=(const ScalarConverter &src);
	ScalarConverter(const ScalarConverter &src);

};

#endif
