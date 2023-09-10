/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:32:56 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/10 15:35:36 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animals.hpp"
#include "dog.hpp"
#include "cat.hpp"
#include "brain.hpp"
#include <iostream>

int main()
{
    // Test 1: Créez et supprimez un chien
    const AAnimal* j = new Dog();
    // AAnimal blabla;
    delete j; // Ne doit pas créer de fuite de mémoire

    // Test 2: Créez et supprimez un chat
    const AAnimal* i = new Cat();
    delete i; // Ne doit pas créer de fuite de mémoire

    // Test 3: Créez un tableau d'animaux (chien et chat) et supprimez-les
    const int numAAnimals = 4;
    AAnimal* AAnimals[numAAnimals];

    for (int k = 0; k < numAAnimals; ++k)
    {
        if (k < numAAnimals / 2)
        {
            AAnimals[k] = new Dog();
        }
        else
        {
            AAnimals[k] = new Cat();
        }
    }

    for (int k = 0; k < numAAnimals; ++k)
    {
        delete AAnimals[k]; // Ne doit pas créer de fuite de mémoire
    }

    return 0;
}



