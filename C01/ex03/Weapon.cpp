/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:35:26 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/08/23 19:48:27 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &type)
{
    this->type = type;
}

Weapon::~Weapon(){
	
};

const std::string& Weapon::getType() const 
{
    return type;
}


void Weapon::setType(const std::string &type)
{
	this->type = type;
}
