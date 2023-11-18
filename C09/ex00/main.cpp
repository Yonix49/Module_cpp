/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:28:51 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/11/18 11:39:08 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include "BitcoinExchange.hpp"



int	main(int ac, char **argv)
{
	if (ac != 2)
	{
		std::cerr << "Error: usage : ./btc <input file>." << std::endl;
		return (1);
	}
	
    BitcoinExchange bitcoin;
    if (bitcoin.get_data_csv() != 0)
	{
		std::cerr << "Error: Invalid Data base" << std::endl;
		return (1);
	}
	else
	{
		bitcoin.parse_input(argv);    
	}
}