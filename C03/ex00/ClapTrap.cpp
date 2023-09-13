/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:03:56 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/13 21:34:05 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Clap Trap Constructor called" << std::endl;
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
}
ClapTrap::~ClapTrap()
{
	std::cout << "Clap Trap Destructor called" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "Copy constructor called for ClapTrap" << std::endl;
	this->name = other.name;
	this->hit_points = other.hit_points;
	this->energy_points = other.energy_points;
	this->attack_damage = other.attack_damage;
}
ClapTrap::ClapTrap(const std::string name)
{
	std::cout << "ClapTrap " << name << " Constructor called" << std::endl;
	this->name = name;
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
}
ClapTrap& ClapTrap::operator=(const ClapTrap &other)
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
void ClapTrap::attack(const std::string &target)
{
	if (this->energy_points == 0 || this->hit_points == 0)
		return;
	--energy_points;
	std::cout << name <<  " attacks " << target <<  " causing " << attack_damage << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->energy_points == 0 || this->hit_points == 0)
		return;
	std::cout << name <<  " take " << amount << " damage!"<< std::endl;
	this->hit_points -= amount;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energy_points == 0 || this->hit_points == 0)
		return;
	std::cout << name <<  " heal itself for " << amount << " hit points" << std::endl;
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
