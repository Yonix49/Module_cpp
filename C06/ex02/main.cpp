/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 09:37:46 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/10/06 09:37:46 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>   // Pour time

Base *generate(void)
{
	int r = rand() % 3; // Compris entre 0 et 2
	if (r == 0)
	{
		std::cout << "Creating A" << std::endl;
		return (new A);
	}
	else if (r == 1)
	{
		std::cout << "Creating B" << std::endl;
		return (new B);
	}
	else
	{
		std::cout << "Creating C" << std::endl;
		return (new C);
	}
};

void identify(Base *p)
{ // Identifie un type en fonction de son pointeur de base
	if (dynamic_cast<A *>(p))
	{
		std::cout << "A" << std::endl;
	}
	else if (dynamic_cast<B *>(p))
	{
		std::cout << "B" << std::endl;
	}
	else if (dynamic_cast<C *>(p))
	{
		std::cout << "C" << std::endl;
	}
}
void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (const std::exception &e)
	{
	}
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (const std::exception &e)
	{
	}
	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (const std::exception &e)
	{
	}
}
int main() {
    std::srand(static_cast<unsigned int>(std::time(0)));

    Base* randomObject = generate();

    std::cout << "Identifying the type: ";
    identify(randomObject);

    delete randomObject;

    return 0;
}