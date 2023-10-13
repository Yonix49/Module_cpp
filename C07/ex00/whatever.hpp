/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:31:35 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/10/12 15:03:00 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_WHATEVER
#define DEF_WHATEVER


	template <typename T>
	void swap(T &a, T &b)// Passer par les adresses
	{
		T temp;
		temp = a;
		a = b;
		b = temp;
	}

	template <typename T>
	T min(T a, T b)
	{
		if (a < b)
		{
			return (a);
		}
		else
			return (b);
	}

	template <typename T>
	T max(T a, T b)
	{
		if (a > b)
		{
			return (a);
		}
		else
			return (b);
	}
#endif