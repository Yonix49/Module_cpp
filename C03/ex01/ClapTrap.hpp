/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:03:34 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/13 18:23:28 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_CLAPTRAP
#define DEF_CLAPTRAP
#include <cstring>
#include <iostream>
#include <string>
class ClapTrap 
{
	public:
	ClapTrap();
	~ClapTrap();
	ClapTrap(const ClapTrap &other);
	ClapTrap(const std::string name);
	ClapTrap& operator=(const ClapTrap &other);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	
	std::string getName() const;
	unsigned int getEnergyPoints() const;
	unsigned int getHitPoints() const;
	unsigned int getAttackDamage() const;
	
	protected:
	std::string name; 
	unsigned int hit_points;
	unsigned int energy_points;
	unsigned int attack_damage;
	
};

#endif