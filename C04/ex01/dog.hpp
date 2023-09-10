/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:30:14 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/10 13:35:03 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_DOG
#define DEF_DOG

#include "animals.hpp"
#include "brain.hpp"
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
		Dog(const Dog &src);
		
		void makeSound() const ;
		void copyIdeas(const Dog &other);
		std::string getType() const ;
		Brain* getBrain() const;


	private:
		Brain* brain;
};



#endif