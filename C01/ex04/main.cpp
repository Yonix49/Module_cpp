/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:23:34 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/11 20:48:15 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "replace.hpp"
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include "sed.hpp"



int main (int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Veuillez entrez  3 arguments : <filename> <string> <string>" << std::endl;
		return (3);
	}
	std::string file_name = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	if (s1.empty() || s2.empty())
	{
		std::cout << "Remplissez vos string ! ! ! !" << std::endl;
		return (1);
	}
	replace(s1, s2, file_name);


	return (0);
}