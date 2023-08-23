/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:54:41 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/08/23 16:01:12 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{	
};
Zombie::Zombie(std::string name)
{
	this->name = name;
};

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
Zombie::~Zombie()
{
	std::cout << "Zombie " << name << " destroyed !" << std::endl;	
};
Zombie *Zombie::newZombie(std::string name)
{
	return new Zombie(name);
}
Zombie Zombie::Horde_name(std::string name)
{
	return Zombie(name);
}
void Zombie::randomChump(std::string name)
{
	Zombie* zombie = newZombie(name);
	zombie->announce();
	// delete zombie
	// announce();
}
