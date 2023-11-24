/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:45:27 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/09 16:25:06 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string> 
#include <cstring> 

int main (int ac, char **argv)
{
	int i = 1;
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	else
	{
		while (i < ac)
		{
			int j = 0;
			while (argv[i][j])
			{
				argv[i][j] = toupper(argv[i][j]);
				j++;
			}
			std::cout << argv[i];
			i++;
		}
	}
	std::cout << std::endl;
	return (0);
}