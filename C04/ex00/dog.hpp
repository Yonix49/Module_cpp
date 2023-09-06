/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:30:14 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/06 17:07:41 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_DOG
#define DEF_DOG

#include "animals.hpp"
#include <cstring>
#include <iostream>
#include <string>
class Dog : public Animal 
{
	public:
	Dog();
	~Dog();
	Dog(const std::string type);
	Dog &operator=(const Dog &other);
	void makeSound() const override;
	Dog(const Dog &src);
	std::string getType() const override;
};



#endif