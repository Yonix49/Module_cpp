/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 17:52:38 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/13 19:50:34 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	ScavTrap david("David");
	ClapTrap goliath("Goliath");
	
	std::cout << "Name: " << david.getName() << std::endl;
	std::cout << "Hit points: " << david.getHitPoints() << std::endl;
	std::cout << "Energy points: " << david.getEnergyPoints() << std::endl;
	std::cout << "Attack damage: " << david.getAttackDamage() << std::endl;
	david.attack("Goliath");
	goliath.takeDamage(david.getAttackDamage());
	std::cout << "Hit points: " << goliath.getHitPoints() << std::endl;
	david.guardGate();
	goliath.beRepaired(20);
	std::cout << "Name: " << goliath.getName() << std::endl;
	std::cout << "Hit points: " << goliath.getHitPoints() << std::endl;
	std::cout << "Energy points: " << goliath.getEnergyPoints() << std::endl;
	std::cout << "Attack damage: " << goliath.getAttackDamage() << std::endl;

	return 0;
}

