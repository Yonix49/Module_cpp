/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:03:34 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/13 21:39:20 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_SCAVTRAP
#define DEF_SCAVTRAP
#include <cstring>
#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	~ScavTrap();
	ScavTrap& operator=(const ScavTrap &other);
	ScavTrap(const ScavTrap &src);
	ScavTrap(const std::string name);
	void attack(const std::string& target);
	void guardGate();
};

#endif