/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:30:40 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/09 18:35:17 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dog.hpp"

Dog::Dog()
{
    std::cout << "Basic constructor called for a Dog" << std::endl;
}
Dog::~Dog()
{
    std::cout << "Destructor called for a Dog" << std::endl;
}
Dog& Dog::operator=(const Dog &other)

{
	if (this != &other)
	{
		this->type = other.type;
	}
	return *this;
}
Dog::Dog(const Dog &src) : Animal(src)
{
    std::cout << "Dog Copy constructor called" << std::endl;
}

Dog::Dog(const std::string type)
{
	this->type = type;
	std::cout << "Dog Constructor" << type << "called" << std::endl;
}
void Dog::makeSound() const
{
	std::cout << "Dog makes a woof sound." << std::endl;
}
std::string Dog::getType() const
{
    return "Dog";
}


