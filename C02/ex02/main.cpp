/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:25:29 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/08/27 15:49:53 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "fixed.hpp"
#include <iostream>
int main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;

	// My main //
	//  Fixed a(5.05f);
    // Fixed b(2.5f);
    // Fixed c;

    // std::cout << "a: " << a << std::endl;
    // std::cout << "b: " << b << std::endl;

    // c = a + b;
    // std::cout << "c = a + b: " << c << std::endl;

    // c = a - b;
    // std::cout << "c = a - b: " << c << std::endl;

    // c = a * b;
    // std::cout << "c = a * b: " << c << std::endl;

    // c = a / b;
	// std::cout << "a = " << a << std::endl;
	// std::cout << "b = " << b << std::endl;
    // std::cout << "c = a / b: " << c << std::endl;
	return 0;
}