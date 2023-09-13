/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:03:56 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/13 21:49:02 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap constructor called" << std::endl;
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
}
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " destructor called" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->name = other.name;
	this->hit_points = other.hit_points;
	this->energy_points = other.energy_points;
	this->attack_damage = other.attack_damage;
}
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->hit_points = other.hit_points;
		this->energy_points = other.energy_points;
		this->attack_damage = other.attack_damage;
	}
		return *this;
}
ClapTrap::ClapTrap(const std::string name)
{
	std::cout << "ClapTrap constructor called" << std::endl;
	this->name = name;
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
}
void ClapTrap::attack(const std::string &target)
{
	if (this->energy_points == 0)
	{
		std::cout << "ClapTrap " << name << " has no energy!" << std::endl;
		return ;
	}
	else if (this->hit_points == 0)
	{
		std::cout << "ClapTrap " << name << " has no hit points!" << std::endl;
		return ;
	}
	if (energy_points > 0)
	{
		energy_points--;
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
	}
}
void ClapTrap::takeDamage(unsigned int amount)
{	if (hit_points > 0)
	{
		hit_points -= amount;
		std::cout << name <<  " take " << amount << " damage!"<< std::endl;
	}
	if (hit_points == 0)
		std::cout << name << " is dead! " << std::endl;
	
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energy_points == 0 || this->hit_points == 0)
	{
		std::cout << "ClapTrap " << name << " has no energy!" << std::endl;
		return;
	}
	std::cout << name << " heal it for " << amount << " hit points"<< std::endl;
	--this->energy_points;
	this->hit_points += amount;
}
std::string ClapTrap::getName() const
{
	return name;
}

unsigned int ClapTrap::getEnergyPoints() const
{
	return energy_points; 
}

unsigned int ClapTrap::getHitPoints() const
{
	return hit_points; 
}

unsigned int ClapTrap::getAttackDamage() const
{
	return attack_damage; 
}
