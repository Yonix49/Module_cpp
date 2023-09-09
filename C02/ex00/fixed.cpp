/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:26:36 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/09 22:24:27 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"
#include <iostream>
#include <string>

const int Fixed::nb_bits = 8;

Fixed::Fixed(){
	this->a = 0;
	std::cout << "Default constructor called" << std::endl;
};
Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
};

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->a = other.getRawBits();
}
Fixed& Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) //Je compare l'adresse memoire des deux objets si c'est pas les memes 
	{//Bug en cas de copie a = a par exemple
        this->a = other.getRawBits();
    }
    return *this;
}

bool Fixed::operator==(const Fixed &other) const
{
	// std::cout << "Copy assignment operator called" << std::endl;
	return (this->a == other.a);
}
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->a;
}
void Fixed::setRawBits(int const raw)
{
	this->a = raw;	
}