/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:48:54 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/06 16:49:57 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_WrongCat
#define DEF_WrongCat

#include "WrongAnimal.hpp"
#include <cstring>
#include <iostream>
#include <string>
class WrongCat : public WrongAnimal
{
	public:
	WrongCat();
	~WrongCat();
	WrongCat &operator=(const WrongCat &other);
	WrongCat(const WrongCat &src);
	WrongCat(const std::string type);
	void makeSound() const ;
	std::string getType() const;


};



#endif