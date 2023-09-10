/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:48:26 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/10 13:35:30 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DEF_CAT
#define DEF_CAT

#include "animals.hpp"
#include <cstring>
#include <iostream>
#include <string>
#include "brain.hpp"
class Cat : public Animal
{
	public:
	Cat();
	~Cat();
	Cat &operator=(const Cat &other);
	Cat(const Cat &src);
	Cat(const std::string type);
	void makeSound() const ;
	std::string getType() const ;
	void copyIdeas(const Cat &other);
	Brain* getBrain() const;

	private:
		Brain* brain;
};



#endif