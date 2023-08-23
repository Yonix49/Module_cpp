/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:54:50 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/08/23 16:17:09 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_ZOMBIE
#define DEF_ZOMBIE
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <stdlib.h>
#include <cstring>
class Zombie
{
public:
	Zombie();
	Zombie(std::string name);
	~Zombie();

	void announce(void);
	Zombie *newZombie(std::string name);
	void randomChump(std::string name);
	Zombie Horde_name(std::string name);
	Zombie* zombieHorde(int N, std::string name);
	std::string set_name(std::string name);


private:
	std::string name;
};

#endif
