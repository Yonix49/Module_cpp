/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:58:01 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/10 14:13:42 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brain.hpp"

Brain::Brain()
{
	int i = 0;
	while (i < 100)
	{
		ideas[i] = "";
		i++;
	}
	std::cout << "Default constructor called for a Brain" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Destructor called for a Brain" << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; ++i)
		{
			this->ideas[i] = other.ideas[i];
		}
	}
	return *this;
}

Brain::Brain(const Brain &src)
{
	std::cout << "Brain Copy constructor called" << std::endl;
	for (int i = 0; i < 100; ++i)
	{
		this->ideas[i] = src.ideas[i];
	}
}

void Brain::copyIdeas(const Brain &other)
{
	for (int i = 0; i < 100; ++i)
	{
		this->ideas[i] = other.ideas[i];
	}
}

std::string Brain::getIdea(int idx) const
{
	return ideas[idx];
}

void Brain::setIdea(int idx, std::string str)
{
	ideas[idx] = str;
}
