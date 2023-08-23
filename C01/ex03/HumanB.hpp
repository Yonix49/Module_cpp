/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:29:39 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/08/23 19:52:36 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_HUMANB
#define DEF_HUMANB
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <stdlib.h>
#include <cstring>
#include "Weapon.hpp"
class HumanB
{
public:
	HumanB(const std::string &name);
	void attack();

	void setWeapon(Weapon &weapon);

private:
	std::string name;
	Weapon *weapon;
};

#endif