/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:34:43 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/11/14 20:02:04 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    
}
BitcoinExchange::~BitcoinExchange()
{
    
}
BitcoinExchange::BitcoinExchange(BitcoinExchange const & src)
{
    *this = src;
}
BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & src)
{
    if (this != &src)
    {
        this->_exchangeRates = src._exchangeRates;
    }
    return (*this);
}

int BitcoinExchange::put_data_csv(std::string date)
{
    float value = 0.0; 
    std::string date_value;
    int i = 0;

    // Extraire la date
    while (date[i] && date[i] != ',')
    {
        date_value += date[i];
        i++;
    }
    if (date[i] == ',')
    {
        i++;
        value = static_cast<float>(atof(date.substr(i).c_str()));
    }
    else
    {
        std::cerr << "Error: Missing comma in line: " << date << std::endl;
        return 1;
    }

    DateValuePair tempPair = {date_value, value};
    _exchangeRates[date_value] = tempPair;
    return 0;
}

int BitcoinExchange::get_data_csv(void)
{
    std::ifstream infile("data.csv");
    if (!infile)
    {
        std::cerr << "Error: infile: " << std::endl;
        exit(1);
    }
    std::string line;
    int i = 0;
    
    while (std::getline(infile, line))
    {
        if (i == 0)
        {
            if (line != "date,exchange_rate")
            {
                std::cerr << "Error: first line is not correct" << std::endl;                
                return (2);
            }
        }
        else
        {
            put_data_csv(line);
        }
        i++;
    }
    return (0);
}