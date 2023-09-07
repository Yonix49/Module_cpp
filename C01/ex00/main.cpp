/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:54:23 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/07 19:20:34 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"



int main()
{
    Zombie *zombie = new Zombie("Boris");
    zombie->announce();
    zombie->randomChump("Momow");

    // Supprimer l'objet zombie
    delete zombie;

    return 0;
}
