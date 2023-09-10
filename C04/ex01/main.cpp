/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:32:56 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/10 14:58:30 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animals.hpp"
#include "dog.hpp"
#include "cat.hpp"
#include "brain.hpp"

#include <vector>
int main()
{
    // Test 1: Créez et supprimez un chien
    const Animal* j = new Dog();
    delete j; // Ne doit pas créer de fuite de mémoire

    // Test 2: Créez et supprimez un chat
    const Animal* i = new Cat();
    delete i; // Ne doit pas créer de fuite de mémoire

    // Test 3: Créez un tableau d'animaux (chien et chat) et supprimez-les
    const int numAnimals = 4;
    Animal* animals[numAnimals];

    for (int k = 0; k < numAnimals; ++k)
    {
        if (k < numAnimals / 2)
        {
            animals[k] = new Dog();
        }
        else
        {
            animals[k] = new Cat();
        }
    }

    for (int k = 0; k < numAnimals; ++k)
    {
        delete animals[k]; // Ne doit pas créer de fuite de mémoire
    }

    return 0;
}

