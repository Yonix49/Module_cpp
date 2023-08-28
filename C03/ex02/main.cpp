/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 17:52:38 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/08/28 15:56:00 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
int main()
{
    ClapTrap clapTrap("Clap");
    ClapTrap anotherClapTrap("Another Clap");

    clapTrap.attack("target_1");
    clapTrap.takeDamage(15);
    clapTrap.beRepaired(10);

    ScavTrap scavTrap("Scav");
    scavTrap.attack("target_2");
    scavTrap.takeDamage(25);
    scavTrap.beRepaired(20);
    scavTrap.guardGate();

    FragTrap fragTrap("Frag");
    fragTrap.attack("target_3");
    fragTrap.takeDamage(30);
    fragTrap.beRepaired(25);
    fragTrap.highFivesGuys();

    return 0;
}


