/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:26:36 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/08/25 19:23:58 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"
using namespace std;
#include <iostream>
#include <string>

Fixed::Fixed(){
	a = 0;
	std::cout << "Default constructor called" << std::endl;
};
Fixed::~Fixed(){
	std::cout << "Destructor constructor called" << std::endl;
	
};

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	a = other.a;
}
bool Fixed::operator==(const Fixed &other) const
{
	return (this->a == other.a);
}
int Fixed::getRawBits(void) const
{
	return a;
}
void Fixed::setRawBits(int const raw)
{
	a = raw;	
}