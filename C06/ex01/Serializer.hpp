/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 17:09:46 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/10/13 10:50:10 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cctype> // Pour isprint
#include <stdint.h>

struct Data
{
	std::string name;
	int value;
};

class Serializer
{

public:
	~Serializer();

	static uintptr_t serialize(Data *ptr);
	static Data* deserialize(uintptr_t raw);

private:
	Serializer(const Serializer &other);
	Serializer &operator=(const Serializer &);
	Serializer();
};

#endif
