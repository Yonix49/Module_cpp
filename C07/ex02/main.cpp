/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:28:51 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/10/13 17:32:03 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <string>


#include <iostream>

#include <iostream>
#include "Array.hpp"

int main()
{
    // Crée un tableau vide
    Array<int> emptyArray;

    // Crée un tableau de 5 éléments initialisés à 0
    Array<int> initializedArray(5);

    // Accède aux éléments du tableau initialisé
    for (unsigned int i = 0; i < initializedArray.Size(); i++)
    {
        initializedArray[i] = i * 10;
    }

    // Affiche les éléments du tableau initialisé
    for (unsigned int i = 0; i < initializedArray.Size(); i++)
    {
        std::cout << initializedArray[i] << " ";//0 10 20 30 40
    }
    std::cout << std::endl;

    // Copie d'un tableau
    Array<int> copiedArray = initializedArray;

    // Modifie le tableau copié
    for (unsigned int  i = 0; i < copiedArray.Size(); i++)
    {
        copiedArray[i] += 1;
    }

    // Vérifie que la modification du tableau copié n'affecte pas l'original
    for (unsigned int  i = 0; i < initializedArray.Size(); i++)
    {
        std::cout << initializedArray[i] << " ";
    }
    std::cout << std::endl;

    // // Accède à un élément en dehors des limites (doit lancer une exception)
    // try
    // {
    //     int value = initializedArray[100]; // Cet index est en dehors des limites
    //     std::cout << "Value: " << value << std::endl;
    // }
    // catch (const std::exception &e)
    // {
    //     std::cerr << "Exception: " << e.what() << std::endl;
    // }

    return 0;
}
