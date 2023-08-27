/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 17:52:38 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/08/27 19:34:54 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ClapTrap clapTrap("ClapTrap");
    clapTrap.attack("target_2");
    clapTrap.takeDamage(15);
    clapTrap.beRepaired(10);

    ScavTrap scavTrap("ScavTrap");
    scavTrap.attack("target_1");
    scavTrap.takeDamage(25);
    scavTrap.beRepaired(20);
    scavTrap.guardGate();

    return 0;
}

