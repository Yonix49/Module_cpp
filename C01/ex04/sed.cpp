/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 22:07:49 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/09 22:09:11 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"
void replace(std::string s1, std::string s2, std::string file_name)
{
	std::ifstream infile((file_name).c_str()); // Ouvrir le fichier en lecture
	if (!infile)
	{
		std::cerr << "Error infile: " << file_name << std::endl;
		exit(1);
	}
	std::ofstream outfile((file_name + ".replace").c_str());
	if (!outfile)
	{
		std::cerr << "Error outfile: " << file_name << std::endl;
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
		if (not infile.eof())
			outfile << "\n";
	}
}