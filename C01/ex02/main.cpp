/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:24:15 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/07 15:34:13 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <stdlib.h>
#include <cstring>

int main () 
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string& stringREF = string;
	std::cout << "Adresse de string: " << &string << std::endl;
	std::cout << "Adresse de stringPTR: " << &stringPTR << std::endl;
	std::cout << "Adresse de stringREF: " << &stringREF << std::endl;
	std::cout << "La valeur de la string: " << string << std::endl;
	std::cout << "La valeur pointee par stringPTR: " << *stringPTR << std::endl;
	std::cout << "La valeur pointee par stringREF: " << stringREF << std::endl;
	
}