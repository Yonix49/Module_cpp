/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:32:56 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/06 17:09:36 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animals.hpp"
#include "dog.hpp"
#include "cat.hpp"

using namespace std;
// int main() 
// {
//     Animal* animal = new Cat();
//     animal->makeSound();  // Appel à la fonction makeSound() de Cat

//     animal = new Dog();
//     animal->makeSound();  // Appel à la fonction makeSound() de Dog

//     delete animal;
//     return 0;
// }
int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	return 0;
}