/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:17:31 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/13 21:58:16 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("")
{
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
	std::cout << "FragTrap" << name << " Constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " Destructor called" << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
	std::cout << "FragTrap " << name << " Constructor called" << std::endl;
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
void FragTrap::attack(const std::string& target)
{
	if (this->energy_points == 0 || this->hit_points == 0)
	{
		std::cout << "FragTrap " << name << " has no energy!" << std::endl;
		return;
	}
	if (energy_points > 0)
	{
		energy_points--;
		std::cout << "FragTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
	}
	else
		std::cout << "FragTrap " << name << " runs out of energy!" << std::endl;
}
FragTrap::FragTrap(const FragTrap &Other)
{
	std::cout << "FragTrap copy Constructor called" << std::endl;
	this->attack_damage = Other.attack_damage;
	this->hit_points = Other.hit_points;
	this->energy_points = Other.energy_points;
	this->name = Other.name;
}


void FragTrap::highFivesGuys() 
{
	std::cout << "FragTrap " << name << " ask a high five!" << std::endl;
}


