/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 19:21:58 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/09 22:12:46 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl test;
	test.complain("warning");
	std::cout << std::endl;
	test.complain("debug");
	std::cout << std::endl;
	test.complain("error");
	std::cout << std::endl;
	test.complain("info");
}