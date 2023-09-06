/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:03:34 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/08/27 19:35:58 by mhajji-b         ###   ########.fr       */
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
	ClapTrap& operator=(const ClapTrap &other);
	ClapTrap(const ClapTrap &other);
	
	ClapTrap(const std::string name);
	
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	
	private:
	std::string name; 
	unsigned hit_points;
	unsigned int energy_points;
	unsigned int attack_damage;
	
};

#endif