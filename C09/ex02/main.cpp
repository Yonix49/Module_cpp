/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:28:51 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/11/17 14:45:05 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char* argv[]) 
{
    if (argc < 2)
	{
		std::cout << "Usage: ./PmergeMe <positive integer sequence as argument> " << std::endl;
		return 1;
	}
	try 
    {
		PmergeMe pmergeme(argc, argv);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
    return 0;
}