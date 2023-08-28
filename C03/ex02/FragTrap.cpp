/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:17:31 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/08/28 16:17:30 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("")
{
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
	std::cout << "FragTrap Constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap " << name << " Constructor called" << std::endl;
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
}

FragTrap& FragTrap::operator=(const FragTrap &Other)
{
	if (this != &Other)
	{
		this->name = Other.name;
		this->hit_points = Other.hit_points;
		this->attack_damage = Other.attack_damage;
		this->energy_points = Other.energy_points;
	}
	return *this;
}

FragTrap::FragTrap(const FragTrap &Other) : ClapTrap(Other)
{
	std::cout << "FragTrap copy Constructor called" << std::endl;
	this->attack_damage = Other.attack_damage;
	this->hit_points = Other.hit_points;
	this->energy_points = Other.energy_points;

}

void FragTrap::highFivesGuys(void)
{
	std::cout << "Hey guys! Let's do some high fives!" << std::endl;
}


