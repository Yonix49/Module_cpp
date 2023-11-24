/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:59:06 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/07 15:40:33 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
    PhoneBook contact;
    std::string nom;
    while (42)
    {
        std::cout << std::endl
                  << "<<<<<<<<<PHONEBOOK'S MENU>>>>>>>>>" << std::endl;
        std::cout << "ADD    : to save a new contact" << std::endl;
        std::cout << "SEARCH : to display a specific contact" << std::endl;
        std::cout << "EXIT   : to quit";
        std::cout << std::endl
                  << "<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>" << std::endl;
        std::getline(std::cin, nom);
        if (std::cin.eof())
            exit(0);
        if (nom == "ADD")
        {
            contact.add(contact);
        }
        else if (nom == "SEARCH")
        {
            contact.search(nom, contact);
        }
        else if (nom == "EXIT")
        {
            std::cout << "Exiting the PhoneBook." << std::endl;
            exit(0);
        }
        else
            std::cout << "Wrong command put a new one!! \n" << std::endl;

    }
    return 0;
}
void PhoneBook::add(PhoneBook &contact)
{
    std::string input = contact.get_question("First name?");
    contact.stock_first_name(input);
    input = contact.get_question("Last name?");
    contact.stock_last_name(input);
    input = contact.get_question("Nickname?");
    contact.stock_nick_name(input);
    input = contact.get_question("Phone number?");
    contact.stock_phone_name(input);
    input = contact.get_question("Darkest secret?");
    contact.stock_darkest(input);
    std::cout << "Contact successfully added to the Phone Book\n" << std::endl;
}
void PhoneBook::search(std::string &nom, PhoneBook &contact)
{
    contact.afficher_contacts();
    std::cout << "\n"
              << std::endl;
    int index = atoi(nom.c_str());
    nom = contact.get_question("Entrez l'index du contact que vous souhaitez afficher compris entre 1 et 8: ");
    index = atoi(nom.c_str());
    while (1)
    {
        if (!nom.empty() && (index >= 1 && index <= 8))
        {
            contact.contacts_index(index);
            break;
        }
        nom = contact.get_question("L'index rentrer n'est pas correct veuillez rentrez un chiffre compris entre 1 et 8: ");
        index = atoi(nom.c_str());
    }
}