/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:27:10 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/08/25 19:21:27 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_FIXED
#define DEF_FIXED
class Fixed
{
private:
	int a;
	const int static nb_bits;

public:
	Fixed();
	Fixed(int define);
	~Fixed();
	Fixed(const Fixed &other){

	};
	bool operator==(const Fixed &other) const;
	

	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif
// • Constructeur par défaut
// • Constructeur de recopie
// • Opérateur d’affectation
// • Destructeur