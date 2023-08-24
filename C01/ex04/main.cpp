/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:23:34 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/08/24 19:06:38 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "replace.hpp"
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

void replace(std::string s1, std::string s2, std::string file_name)
{
	std::ifstream infile(file_name); // Ouvrir le fichier en lecture
	if (!infile)
	{
		std::cerr << "Error infile: " << file_name << std::endl;
		exit(1);
	}
	std::ofstream outfile(file_name + ".replace");
	if (!outfile)
	{
		std::cerr << "Error infile: " << file_name << std::endl;
		exit(3);
	}
	std::string line;
while (std::getline(infile, line))
{
    size_t pos = 0;
    std::string newLine;
    while ((pos = line.find(s1, pos)) != std::string::npos)
    {
        newLine += line.substr(0, pos);
        newLine += s2;
        pos += s1.length();
    }
    if (pos != std::string::npos)// Ici j'ajoute le reste si aucune occurente n'a ete find 
    {
        newLine += line.substr(pos); // Ajoute le reste de la ligne après la dernière occurrence
    }
    outfile << newLine << std::endl;
}
}

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
	replace(s1, s2, file_name);


	return (0);
}