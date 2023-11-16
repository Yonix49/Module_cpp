/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:28:51 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/11/14 19:52:23 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include "BitcoinExchange.hpp"
// je dois parse cette ligne 2011-01-03 | 3
// c'est faux si 2011-01-03 | 3 c'est pas sous cette forme

int parse_input(char **argv)
{
    std::ifstream infile((argv[1]));
	if (!infile)
	{
		std::cerr << "Error: infile: " << argv[1] << std::endl;
		exit(1);
	}
	std::string line;
	int i = 0;
    
	while (std::getline(infile, line))
	{
		if (i == 0)
		{
            if (line != "date | value")
            {
                std::cerr << "Error: first line is not correct" << std::endl;
                
                return (2);
            }
		}
	    else if (parse(line) != 0)
        {
            std::cerr << "Error parsing line: " << i << " " << line << " " << std::endl;
        }   
        else 
        {
            
        } 
		i++;
	}    
    return (0);  
    std::cout << "Parsing ok ! " << std::endl;
	std::cout << "number of lines: " << i << std::endl;
}

int	main(int ac, char **argv)
{
	if (ac != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}
    BitcoinExchange bitcoin;
    (void)(argv);
    bitcoin.get_data_csv();
	parse_input(argv);
    
}