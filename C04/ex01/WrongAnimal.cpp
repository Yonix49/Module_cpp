/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:57:17 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/06 16:20:03 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"



WrongAnimal::WrongAnimal()
{
	std::cout << "Default Constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor called" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	std::cout << "Copy Constructor called called" << std::endl;	
	this->type = src.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	return *this;
}
WrongAnimal::WrongAnimal(std::string type)
{
	this->type = type;
	std::cout << "WrongWrongAnimal Constructor" << type <<"called" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return "WrongAnimal";
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongWrongAnimal make a sound" << std::endl;
}