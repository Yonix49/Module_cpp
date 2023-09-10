/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:18:42 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/10 14:17:58 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cat.hpp"


Cat::Cat()
{
	brain = new Brain();
    std::cout << "Default constructor called for a Cat" << std::endl;
}
Cat::~Cat()
{
	delete brain;
    std::cout << "Destructor called for a Cat" << std::endl;
}
void Cat::copyIdeas(const Cat &other)
{
	this->brain->copyIdeas(*other.brain);
}
Cat& Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	return *this;
}
Cat::Cat(const Cat &src) : Animal(src)
{
    std::cout << "Cat Copy constructor called" << std::endl;
}
Cat::Cat(const std::string type) : Animal(type)
{
	this->type = type;
	std::cout << "Cat " << type << " Constructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Cat makes a meow sound." << std::endl;
}
std::string Cat::getType() const
{
    return "Cat";
}
Brain* Cat::getBrain() const
{
	return brain;
}

// Cat::Cat(const Cat &src)
// {
//     std::cout << "Copy Constructor called for a cat" << std::endl;
// 	this->type = src.type;
// }

