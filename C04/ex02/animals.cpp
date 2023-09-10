/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animals.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:57:17 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/10 15:17:39 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animals.hpp"



AAnimal::AAnimal()
{
	std::cout << "Default Constructor called for AAnimal" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "Destructor called for AAnimal" << std::endl;
}
AAnimal::AAnimal(const AAnimal &src)
{
	std::cout << "Copy Constructor for AAnimal" << std::endl;	
	this->type = src.type;
}

AAnimal& AAnimal::operator=(const AAnimal &other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	return *this;
}
AAnimal::AAnimal(std::string type)
{
	this->type = type;
	std::cout << "AAnimal " << type << " Constructor called" << std::endl;
}

std::string AAnimal::getType() const
{
    return "AAnimals";
}

void AAnimal::makeSound() const 
{
	std::cout << "AAnimal make a sound" << std::endl;
}
