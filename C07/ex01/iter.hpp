/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:31:35 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/10/13 14:29:31 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
template <typename T>
void print(T const &x)
{
	std::cout << x << std::endl;
	return;
}

template <typename R, typename T, typename F>
void iter(R *array, size_t size, F (*f)(T const &))
{
	for (size_t i = 0; i < size; i++)
		f(array[i]);
}


