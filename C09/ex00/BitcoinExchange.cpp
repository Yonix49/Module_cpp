/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:34:43 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/11/17 20:43:51 by mhajji-b         ###   ########.fr       */
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
    _exchangeRates.insert(std::make_pair(date_value, value));
    return 0;
}

int BitcoinExchange::get_data_csv(void)
{
    std::ifstream infile("data.csv");
    if (!infile)
    {
        std::cerr << "Error: no data base " << std::endl;
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
            if (parsing_csv(line) != 0)
            {
                return (1);
            }
            put_data_csv(line);
        }
        i++;
    }
    infile.close();
    return (0);
}
// ! Parsing CSV here //

int BitcoinExchange::parsing_csv(std::string line)
{
    if (line.empty())
    {
        std::cerr << "Error: empty line" << std::endl;
        return (1);
    }
    int i = 0;
    int count_comma = 0;
    while (line[i])
    {
        if (line[i] == ',')
        {
            count_comma++;
        }
        i++;
    }
    if (count_comma != 1)
    {
        std::cerr << "Error: bad format" << std::endl;
        return (1);
    }
    i = 0;
    std::string date;
    std::string value;
    while (line[i] && line[i] != ',')
    {
        date += line[i];
        i++;
    }
    if (line[i] == ',')
    {
        i++;
        while (line[i])
        {
            value += line[i];
            i++;
        }
    }
    else
    {
        std::cerr << "Error: bad format" << std::endl;
        return (1);
    }
    if (parsing_valid_date(date) == 0)
    {
        return (1);
        
    }
    return (0); 
}
int	BitcoinExchange::parse(std::string line)
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
	if (parsing_date(date) != 0)
        return (1);
    else if (parsing_value(value) != 0)
        return (1);
    return (0);
}



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
	
//! Parsing input and calcul rate here //

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
	    if (parse(line) == 0)
        {
		    calcul_rate(line);        
        }
		
		i++;
	}    
    return (0);  
}

int BitcoinExchange::parsing_date(std::string date)
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
            else if (!(atoll(check.c_str()) >= 2008 && atoll(check.c_str()) <= 2023))
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
    if (parsing_valid_date(date) == false)
    {
        return (1);
    }
    return (0);
}

bool BitcoinExchange::parsing_valid_date(std::string date)
{
    int year, month, day;
    char delimiter;

    std::istringstream iss(date);
    iss >> year >> delimiter >> month >> delimiter >> day;
    
    if (!(year >= 0 && month >= 1 && month <= 12 && day >= 1 && day <= 31)) 
    {
        std::cerr << "Error: Invalid date format." << std::endl;
        return false;
    }

    switch (month) {
        case 1:  // Janvier
        case 3:  // Mars
        case 5:  // Mai
        case 7:  // Juillet
        case 8:  // Août
        case 10: // Octobre
        case 12: // Décembre
            if (day < 1 || day > 31) {
                std::cerr << "Error: Invalid day for the given month." << std::endl;
                return false;
            }
            break;

        case 4:  // Avril
        case 6:  // Juin
        case 9:  // Septembre
        case 11: // Novembre
            if (day < 1 || day > 30) {
                std::cerr << "Error: Invalid day for the given month." << std::endl;
                return false;
            }
            break;

        case 2: // Fevrier
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                // Annee bissextile, fevrier a 29 jours
                if (day < 1 || day > 29) {
                    std::cerr << "Error: Invalid day for the given month." << std::endl;
                    return false;
                }
            } else {
                // Annee non bissextile, fevrier a 28 jours
                if (day < 1 || day > 28) {
                    std::cerr << "Error: Invalid day for the given month." << std::endl;
                    return false;
                }
            }
            break;
    }
    return true;
}




// ? Parsing Value here // 


int BitcoinExchange::parsing_value(std::string value) 
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
        else if (!(f_value > 0 && f_value < 1000))
        {
            std::cerr << "Error: value is not in range" << std::endl;
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
        else if (!(i_value > 0 && i_value < 1000))
        {
            std::cerr << "Error: value is not in range" << std::endl;
            return 1; 
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

bool BitcoinExchange::is_float(std::string value)
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
bool BitcoinExchange::is_int(std::string value)
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