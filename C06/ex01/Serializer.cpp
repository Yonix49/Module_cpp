/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:30:16 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/10/09 19:46:19 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::~Serializer(){}

Serializer::Serializer(){}


Serializer &Serializer::operator=(const Serializer &other)
{
    if (this != &other) {
    }
    return *this; // Retournez une référence vers l'objet actuel
}
Serializer::Serializer(const Serializer &other)
{
	(void)(other);
}