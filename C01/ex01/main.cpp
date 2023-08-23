/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:54:23 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/08/23 16:20:48 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

using namespace std;

int main ()
{
	// std::string name = "Louis";
	// Zombie flo(name);
	// flo.randomChump(name);
	Zombie instance;
    Zombie *horde = instance.zombieHorde(8, "bloublou");
	for (int i = 0; i < 8; ++i)
	{
		horde[i].announce();
	}
	delete[] horde;
	return (0);
}
// A re-test pour l'affichage // 