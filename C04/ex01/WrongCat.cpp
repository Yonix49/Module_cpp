/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:48:52 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/06 16:49:10 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:18:42 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/06 16:49:04 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"


WrongCat::WrongCat()
{
    std::cout << "Basic constructor called for a WrongCat" << std::endl;
}
WrongCat::~WrongCat()
{
    std::cout << "Destructor called for a WrongCat" << std::endl;
}
WrongCat::WrongCat(const std::string type) : WrongAnimal(type)
{
	this->type = type;
	std::cout << "WrongCat" << type << "Constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src)
{
    std::cout << "WrongCat Copy constructor called" << std::endl;
}
WrongCat& WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	return *this;
}
void WrongCat::makeSound() const
{
	std::cout << "WrongCat makes a meow sound." << std::endl;
}
std::string WrongCat::getType() const
{
    return "WrongCat";
}


