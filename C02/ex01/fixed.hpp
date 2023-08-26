/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:27:10 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/08/26 20:55:07 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_FIXED
#define DEF_FIXED
#include <ostream>
#include <iostream>
#include <string>
#include <cmath>
class Fixed
{
private:
	int a;
	const int static nb_bits;

public:
	Fixed();
	~Fixed();
	Fixed(const int nb);
	Fixed(const float nb);

	float toFloat(void) const;
	int toInt(void) const;
	Fixed(const Fixed &other);
	bool operator==(const Fixed &other) const;
	Fixed &operator=(const Fixed &other);
    friend std::ostream& operator<<(std::ostream& os, const Fixed& fixed);


	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif
// • Constructeur par défaut
// • Constructeur de recopie
// • Opérateur d’affectation
// • Destructeur