/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 22:07:49 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/10 12:04:15 by mhajji-b         ###   ########.fr       */
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
		size_t pos = 0; // Initialise pos à zéro pour chaque nouvelle ligne
		std::string newLine;

		while (pos < line.length())
		{
			// Recherche de la prochaine occurrence de s1 a partir de la position actuelle
			size_t nextPos = line.find(s1, pos);

			if (nextPos != std::string::npos)
			{
				// Copie les caractères de pos a nextPos dans newLine
				newLine += line.substr(pos, nextPos - pos);

				// Ajoute s2 à la place de s1
				newLine += s2;

				// Met à jour pos pour la prochaine recherche
				pos = nextPos + s1.length();
			}
			else
			{
				// Copie les caractères restants de la ligne
				newLine += line.substr(pos);
				break; // Sort de la boucle while, car il n'y a plus d'occurrence de s1
			}
		}
		outfile << newLine << std::endl;
	}
}