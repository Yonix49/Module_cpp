/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:34:50 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/11/14 16:58:16 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <algorithm>
# include <fstream>
# include <iostream>
# include <map>
# include <string>
#   include <cstdlib>
# include <vector>
class BitcoinExchange
{
  public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(BitcoinExchange const &src);
	BitcoinExchange &operator=(BitcoinExchange const &src);

	int get_data_csv(void);
	int put_data_csv(std::string date);

  private:
	struct		DateValuePair
	{
		std::string date;
		float	exchangeRate;
	};
    
	std::map<std::string, DateValuePair> _exchangeRates;
};


int parsing_date(std::string date);

bool			is_float(std::string value);

bool			is_int(std::string value);

int				parsing_value(std::string value);

int				parse(std::string line);

#endif