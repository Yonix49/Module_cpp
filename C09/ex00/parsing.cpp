/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:33:00 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/11/14 16:15:32 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include <iostream>
#include <string>
#include "BitcoinExchange.hpp"

int parsing_date(std::string date)
{
    int i = 0;
    int count_dash = 0;
    int checking = 0;
    std::string check;
    
    while (date[i])
    {
        if (date[i] == '-')
            count_dash++;
        i++;
    }
    if (count_dash != 2)
    {
        std::cerr << "Error: date format is not correct" << std::endl;
        return (1);
    }
    
    i = 0;
    while (date[i])
    {
        if (date[i] != '-')
        {
            check += date[i];
        }
        else if (date[i] == '-' && checking == 0)// check years
        {
            if (check.size() != 4 || check.empty())
            {
                std::cerr << "Error: bad input => "  << date << std::endl;
                std::cerr << "Error: years format is not correct" << std::endl;
                return (1);
            }
            else if (!(atoll(check.c_str()) >= 2011 && atoll(check.c_str()) <= 2023))
            {
                std::cerr << "Error: bad input => "  << date << std::endl;
                std::cerr << "Error: years not in range is not correct" << std::endl;
                
                return (1);
            }
            checking++;
            check.clear();
        }
        else if (date[i] == '-' && checking == 1)// check month
        {
            if (check.size() != 2 || check.empty())
            {
                std::cerr << "Error: bad input => "  << date << std::endl;
                std::cerr << "Error: month format is not correct" << std::endl;
                return (1);
            }
            else if (!(atoll(check.c_str()) >= 01 && atoll(check.c_str()) <= 12))
            {
                std::cerr << "Error: bad input => "  << date << std::endl;
                std::cerr << "Error: month not in range is not correct" << std::endl;
                return (1);
            }
            checking++;
            check.clear();
        }
        if (checking == 2)
        {   
            i++;
            while (date[i])
            {
                check += date[i];
                i++;
            }
            if (check.size() != 3 || check.empty())
            {
                std::cerr << "Error: bad input => "  << date << std::endl;
                std::cerr << "Error: days format is not correct" << std::endl;
                return (1);
            }
            else if (!(atoll(check.c_str()) >= 01 && atoll(check.c_str()) <= 31))
            {
                std::cerr << "Error: bad input => "  << date << std::endl;
                std::cerr << "Error: days not in range is not correct" << std::endl;
                return (1);
            }
            break;
        }
        i++;
    }
    return (0);
}

bool is_float(std::string value)
{
    int i = 0;
    int dot = 0;
    while (value[i])
    {
        if (value[i] == '.')
        {
            dot++;
            if (value[i + 1] == '\0' && !(value[i - 1] >= '0' && value[i - 1] <= '9'))
            {
                std::cerr << "Error: value is an incorrect float value" << std::endl;
                return (false);
            }
        }
        i++;
    }
    if (dot == 1)
    {
        return (true);
    }
    else 
    {
        return (false);
    }
}
bool is_int(std::string value)
{
    int i = 0;
    while (value[i])
    {
        if (!(value[i] >= '0' && value[i] <= '9'))
        {
            return (false);
        }
        i++;
    }
    return (true);

}

int parsing_value(std::string value) 
{
    int flag_float = 0;
    int flag_int = 0;
    if (value.empty()) 
    {
        std::cerr << "Error: there is no value" << std::endl;
        return 1;
    }
    
    if (is_float(value) == true)
    {
        flag_float++;
    }
    if (flag_float == 0 && is_int(value) == true)
    {
        flag_int++;
    }

    if (flag_float == 1)
    {
        float f_value = std::strtof(value.c_str(), NULL);
        if (f_value < 0) 
        {
            std::cerr << "Error: value is negative" << std::endl;
            return 1;
        }
    }
    if (is_int(value) == true)
    {
        long long i_value = std::atoll(value.c_str());
        if (i_value < 0) 
        {
            std::cerr << "Error: not a positive number" << std::endl;
            return 1;
        }
        else if (i_value >= 2147483647)
        {
            std::cerr << "Error: too large a number." << std::endl;
            return (1);
        }
    }
    if (flag_float == 0 && flag_int == 0)
    {
        if (value[0] == '-')
        {
            std::cerr << "Error: not a positive number" << std::endl;
            return (1);
        }
        std::cerr << "Error: value is not a float or int" << std::endl;
        return 1;
    }


    return 0;
}
int	parse(std::string line)
{
	// long long	result;
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
	if (parsing_date(date) != 0)
        return (1);
    else if (parsing_value(value) != 0)
            return (1);

	return (0);
}