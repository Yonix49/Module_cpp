/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 19:48:04 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/08/25 18:02:53 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl(){

};
Harl::~Harl(){

};
void Harl::complain(std::string level)
{
	void (Harl::*func[])() = { // Tableau fonction membre
		&Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
	};
	
	std::string word[4] = {"debug", "info", "warning", "error"};
	for (int i = 0; i < 4; i++)
	{
		if (word[i].compare(level) == 0)// Fonctionne comment strcmp
		{
			(this->*(func[i]))();
			break;
		}
	}
}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !"	<<std::endl;
}

void Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put "
              << "enough bacon in my burger ! If you did, I wouldn't be asking for more !" 
              << std::endl;
}

void Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming "
              << "for years whereas you started working here since last month." 
              << std::endl;
}

void Harl::error(void)
{
    std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}
