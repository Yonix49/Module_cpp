/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:30:40 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/10 15:22:51 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dog.hpp"
#include "brain.hpp"

Dog::Dog()
{
	brain = new Brain();
	std::cout << "Default constructor called for a Dog" << std::endl;
}
Dog::~Dog()
{
	delete brain;
	std::cout << "Destructor called for a Dog" << std::endl;
}
void Dog::copyIdeas(const Dog &other)
{
	this->brain->copyIdeas(*other.brain);
}
Dog &Dog::operator=(const Dog &other)

{
	if (this != &other)
	{ 
		delete this->brain;

		this->brain = new Brain();
	    this->copyIdeas(other); 
	}
	return *this;
}

Dog::Dog(const Dog &src) : AAnimal(src) 
{
    this->brain = new Brain();
	this->brain->copyIdeas(*src.brain);
    std::cout << "Copy Constructor called for a Dog" << std::endl;
}
Brain* Dog::getBrain() const
{
	return brain;
}

Dog::Dog(const std::string type)
{
	this->type = type;
	std::cout << "Dog Constructor " << type << " called" << std::endl;
}
void Dog::makeSound() const
{
	std::cout << "Dog makes a woof sound." << std::endl;
}
std::string Dog::getType() const
{
	return "Dog";
}
