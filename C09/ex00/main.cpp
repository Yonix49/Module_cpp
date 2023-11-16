/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:28:51 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/11/16 12:04:07 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include "BitcoinExchange.hpp"
int BitcoinExchange::calcul_rate(std::string line)
{
	int			i;

	std::string date;
	std::string value;
	i = 0;
	while (line[i] != '|')
	{
		date += line[i];
		i++;
	}
	if (line[i] != '|')
	{
		std::cerr << "Error: | not found bad format" << std::endl;
		return (1);
	}
	i += 2;
	while (line[i])
	{
		value += line[i];
		i++;
	}
	std::map<std::string, float>::const_iterator it = _exchangeRates.find(date);
	
    if (it != _exchangeRates.end())
    {
        std::cout << "Date found: " << it->first << std::endl;
        return true;
    }
    else
    {
        it = _exchangeRates.lower_bound(date);
        if (it == _exchangeRates.begin())
        {
            std::cerr << "Error: No lower date found in the database." << std::endl;
            return false;
        }
        --it;
        date = it->first;
		float f_value = std::strtof(value.c_str(), NULL);
        f_value = f_value * it->second;
		std::cout << date << " => " << value << " = " << f_value << std::endl;
        return true;
    }
}	
	

int BitcoinExchange::parse_input(char **argv)
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
            // std::cerr << "Error parsing line: " << i << " " << line << " " << std::endl;
        }   
        else 
        {
			calcul_rate(line);
        } 
		i++;
	}    
    return (0);  
}

int	main(int ac, char **argv)
{
	if (ac != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}
	
    BitcoinExchange bitcoin;
    bitcoin.get_data_csv();
	bitcoin.parse_input(argv);    
}