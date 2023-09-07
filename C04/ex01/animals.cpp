/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:57:17 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/06 16:20:03 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animals.hpp"



Animal::Animal()
{
	std::cout << "Default Constructor called for Animal" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Destructor called for Animal" << std::endl;
}
Animal::Animal(const Animal &src)
{
	std::cout << "Copy Constructor for Animal" << std::endl;	
	this->type = src.type;
}

Animal& Animal::operator=(const Animal &other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	return *this;
}
Animal::Animal(std::string type)
{
	this->type = type;
	std::cout << "Animal" << type << "Constructor called" << std::endl;
}

std::string Animal::getType() const
{
    return "Animals";
}

void Animal::makeSound() const 
{
	std::cout << "Animal make a sound" << std::endl;
}
