/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:34:50 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/11/17 20:27:15 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include <map>
#include <iomanip>
class BitcoinExchange
{
  public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(BitcoinExchange const &src);
	BitcoinExchange &operator=(BitcoinExchange const &src);

	int 			get_data_csv(void);
	int 			put_data_csv(std::string date);
	int 			parse_input(char **argv);
	int 			parsing_date(std::string date);
	bool			is_float(std::string value);
	bool			is_int(std::string value);
	int				parse(std::string line);
	int 			parsing_value(std::string value);
	int 			calcul_rate(std::string line);
	bool 			parsing_valid_date(std::string date);
	int 			parsing_csv(std::string line);

  private:
	std::map<std::string, float> _exchangeRates;
};


#endif