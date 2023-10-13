/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:28:51 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/10/13 15:14:26 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <string>

#include "iter.hpp"



#include <iostream>

int main()
{
	std::string str_array[] = {"Hello", "World", "C++", "Templates"};
	int abcd[] = {0, 1, 2, 3};
	char str[] = {'a', 'b', 'c', 'd'};
	double arrayo [] = {2.3, 1.2, 9.3, 7.2};
	iter(str_array, 4, print<std::string>);
	//Precise le type generique utilise n'importe quelle type de donnees
	std::cout << std::endl;
	iter(abcd, 4, print<int>);
	std::cout << std::endl;
	iter(str, 4, print<char>);
	std::cout << std::endl;
	iter(arrayo, 4, print<double>);
	
	return 0;
}