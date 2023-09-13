/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:23:17 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/13 21:45:08 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << name << " Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src)
{
    std::cout << "ScavTrap Copy constructor called" << std::endl;
	*this = src;
}
ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->hit_points = other.hit_points;
		this->attack_damage = other.attack_damage;
		this->energy_points = other.energy_points;
	}
	return *this;
}
void ScavTrap::attack(const std::string& target)
{
	if (this->energy_points == 0 || this->hit_points == 0)
	{
		std::cout << "ScavTrap " << name << " has no energy!" << std::endl;
		return;
	}
	if (energy_points > 0)
	{
		energy_points--;
		std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ScavTrap " << name << " runs out of energy!" << std::endl;
}
ScavTrap::ScavTrap()
{
	std::cout << "Basic ScavTrap" << name <<  " constructor called" << std::endl;
}
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " destructor called" << std::endl;
}
void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is on gate keeper mode !" <<std::endl;  
}
