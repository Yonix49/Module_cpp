/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:28:51 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/10/14 10:16:55 by mhajji-b         ###   ########.fr       */
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
    std::cout << "INT TEST" << std::endl;
    Array<int> emptyArray;

    Array<int> initializedArray(5);
    for (unsigned int i = 0; i < initializedArray.Size(); i++)
    {
        initializedArray[i] = i * 10;
    }

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

    for (unsigned int  i = 0; i < copiedArray.Size(); i++)
    {
        std::cout << copiedArray[i] << " ";
    }
    std::cout << std::endl;

    try
    {
        int value = initializedArray[2]; // Cet index n'est pas en dehors des limites
        std::cout << "Value: " << value << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    try
    {
        int value = initializedArray[6595]; // Cet index est en dehors des limites
        std::cout << "Value: " << value << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "DOUBLE TEST !! " << std::endl;

    Array<double> doubleArray(5);
    for (unsigned int i = 0; i < doubleArray.Size(); i++)
    {
        doubleArray[i] = i * 10.3;
    }

    for (unsigned int i = 0; i < doubleArray.Size(); i++)
    {
        std::cout << doubleArray[i] << " ";//0 10 20 30 40
    }
    std::cout << std::endl;

    // Copie d'un tableau
    Array<double> double_coppied_array = doubleArray; 
    // Modifie le tableau copié
    for (unsigned int  i = 0; i < double_coppied_array.Size(); i++)
    {
        double_coppied_array[i] += 1;
    }
    
    // Verifie que la modification du tableau copié n'affecte pas l'original
    for (unsigned int  i = 0; i < double_coppied_array.Size(); i++)
    {
        std::cout << double_coppied_array[i] << " ";
    }
    std::cout << std::endl;

    try
    {
        double value = doubleArray[4]; // Cet index est en dehors des limites
        std::cout << "Value: " << value << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    try
    {
        double value = doubleArray[6595]; // Cet index est en dehors des limites
        std::cout << "Value: " << value << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
