/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:07:45 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/07 15:33:55 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"


HumanA::HumanA(const std::string& name, Weapon& weapon) : name(name), weapon(weapon)
{

}
void HumanA::attack()
{
	std::cout << name << " attacks with their " << weapon.getType() <<std::endl;
}