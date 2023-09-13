/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:03:34 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/13 21:53:41 by mhajji-b         ###   ########.fr       */
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
	ScavTrap(const std::string name);
	ScavTrap(const ScavTrap &src);
	ScavTrap& operator=(const ScavTrap &other);
	void attack(const std::string& target);

	void guardGate();
};

#endif