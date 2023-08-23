/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:40:05 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/08/23 19:48:32 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_WEAPON
#define DEF_WEAPON
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <stdlib.h>
#include <cstring>

class Weapon
{
	public:
	Weapon(const std::string& type);
	~Weapon();
		const std::string& getType() const;

		void setType(const std::string &type);

	private:
	std::string type;
};

#endif