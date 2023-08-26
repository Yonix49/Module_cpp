/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:26:36 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/08/26 21:25:27 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"


using namespace std;
const int Fixed::nb_bits = 8;

Fixed::Fixed()
{
	this->a = 0;
	std::cout << "Default constructor called" << std::endl;
};
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
};

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}
Fixed::Fixed(const int nb)
{
	std::cout << "Int constructor called" << std::endl;
	a = nb << nb_bits;
}

Fixed& Fixed::operator= (const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) //Je compare l'adresse memoire des deux objets si c'est pas les memes 
	{//Bug en cas de copie a = a par exemple
        this->a = other.a;
    }
    return *this;
}
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat(); // Utilisez la fonction toFloat pour convertir en virgule flottante et l'insérer dans le flux
    return os; // Retourne le flux de sortie
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
float Fixed::toFloat(void) const 
{	
	return (static_cast<float>(this->a) / (1 << Fixed::nb_bits));
	//1 Je convertie la valeur en float exp : 256 devient 256.0
	//2 Je calcule la base de conversion donc 2p8 256
}

int Fixed::toInt() const 
{
    return this->a >> nb_bits; //  je delete la partie fractionnaire
}
Fixed::Fixed(const float nb) {
	std::cout << "Float constructor called" << std::endl;
	a = static_cast<int>(roundf(nb * (1 << nb_bits))); // Calcul du nombre entier à partir du flottant
}