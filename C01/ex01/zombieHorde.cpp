/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:55:44 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/07 15:33:51 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"



std::string Zombie::set_name(std::string name)
{
	return this->name = name;
}
Zombie* Zombie::zombieHorde(int N, std::string name)
{
	Zombie *horde = new Zombie[N];
	int i = 0;
	while (i < N)
	{
		horde[i] = set_name(name);
		i++;
	}
	return horde;
}
