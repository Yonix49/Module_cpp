/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:07:41 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/08/23 19:53:48 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"
using namespace std;

HumanB::HumanB(const std::string& name) : name(name)
{

}
void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
void HumanB::attack()
{
	std::cout << name << "attacks with their" << weapon->getType() <<std::endl;
}