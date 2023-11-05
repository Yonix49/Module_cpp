/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:25:00 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/10/13 17:27:34 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <limits.h>
#include <list>
#include <map>
#include <stack>
#include <string>
#include <vector>

template <typename T>
class MutantStack : public std::stack<T>
{
  public:
	typedef typename std::stack<T>::container_type::iterator iterator; // Lecture et ecriture 
	typedef typename std::stack<T>::container_type::const_iterator const_iterator; // Lecture only

	iterator begin()
	{
		return (this->c.begin());
	}
	iterator end()
	{
		return (this->c.end());
	}

	const_iterator cbegin() const
	{
		return (this->c.cbegin());
	}
	const_iterator cend() const
	{
		return (this->c.cend());
	}

	~MutantStack();
	MutantStack(const MutantStack &src);
	MutantStack &operator=(const MutantStack &src);
	MutantStack();

  private:
};

#include "MutantStack.tpp"
