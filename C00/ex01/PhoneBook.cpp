/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:54:15 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/07 18:43:08 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstring>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : nextIndex(0) {}

PhoneBook::~PhoneBook() {}

std::string PhoneBook::get_question(const std::string &question)
{
    std::string reponse;
    std::cout << question << " " << std::endl;

    std::getline(std::cin, reponse);
    if (std::cin.eof())
        exit(0);
    return reponse;
}

void PhoneBook::stock_first_name(std::string nom)
{
    if (nextIndex == 8)
    {
        nextIndex = 0; 
    }
    while (nextIndex < 8 && nom.empty())
    {
        std::cout << "Le champ ne peut pas être vide. Veuillez entrer à nouveau : " << std::endl;
        std::getline(std::cin, nom);
        if (std::cin.eof())
            exit(0);
    }
    if (nextIndex < 8 && !nom.empty())
    {
        contact[nextIndex].setFirstName(nom);
    }
}


void PhoneBook::stock_last_name(std::string nom)
{
    while (nextIndex < 8 && nom.empty())
    {
        std::cout << "Le champ ne peut pas être vide. Veuillez entrer à nouveau : " << std::endl;
        std::getline(std::cin, nom);
        if (std::cin.eof())
            exit(0);
    }
    if (nextIndex < 8)
    {
        contact[nextIndex].setLastName(nom);
    }
}

void PhoneBook::stock_nick_name(std::string nom)
{
    while (nextIndex < 8 && nom.empty())
    {
        std::cout << "Le champ ne peut pas être vide. Veuillez entrer à nouveau : " << std::endl;
        std::getline(std::cin, nom);
        if (std::cin.eof())
            exit(0);
    }
    if (nextIndex < 8)
    {
        contact[nextIndex].setNickname(nom);
    }
}

void PhoneBook::stock_phone_name(std::string nom)
{
    while (nextIndex < 8 && nom.empty())
    {
        std::cout << "Le champ ne peut pas être vide. Veuillez entrer à nouveau : " << std::endl;
        std::getline(std::cin, nom);
        if (std::cin.eof())
            exit(0);
    }
    if (nextIndex < 8)
    {
        contact[nextIndex].setPhoneNumber(nom);
    }
}

void PhoneBook::stock_darkest(std::string nom)
{
    while (nextIndex < 8 && nom.empty())
    {
        std::cout << "Le champ ne peut pas être vide. Veuillez entrer à nouveau : " << std::endl;
        std::getline(std::cin, nom);
        if (std::cin.eof())
            exit(0);
    }
    if (nextIndex < 8)
    {
        contact[nextIndex].setDarkestSecret(nom);
        nextIndex++;
    }
}

void PhoneBook::afficher_contacts()
{
    int i = 0;
    std::cout << std::setw(10) << "INDEX"
              << " | "
              << std::setw(10) << "FIRST NAME"
              << " | "
              << std::setw(10) << "LAST NAME"
              << " | "
              << std::setw(10) << "NICKNAME" << std::endl;

    while (i < 8)
    {
        std::cout << std::setw(10) << i + 1 << " | "
                  << std::setw(10) << (contact[i].getFirstName().length() > 10 ? contact[i].getFirstName().substr(0, 9) + "." : contact[i].getFirstName()) << " | "
                  << std::setw(10) << (contact[i].getLastName().length() > 10 ? contact[i].getLastName().substr(0, 9) + "." : contact[i].getLastName()) << " | "
                  << std::setw(10) << (contact[i].getNickName().length() > 10 ? contact[i].getNickName().substr(0, 9) + "." : contact[i].getNickName()) << std::endl;
        // Condition ? (vrai) | (faux)
        i++;
    }
}

void PhoneBook::contacts_index(int index)
{
    
    std::cout << std::setw((10)) << "INDEX"
              << " | "
              << std::setw(contact[index - 1].getFirstName().length()) << "FIRST NAME"
              << " | "
              << std::setw(contact[index - 1].getLastName().length()) << "LAST NAME"
              << " | "
              << std::setw(contact[index - 1].getNickName().length()) << "NICKNAME" << std::endl;
    if (nextIndex >= index - 1)
    {
        std::cout << std::setw(10) << (index) << " | "
          << std::setw(contact[index - 1].getFirstName().length()) << (contact[index - 1].getFirstName()) << " | "
          << std::setw(contact[index - 1].getLastName().length()) << (contact[index - 1].getLastName()) << " | "
          << std::setw(contact[index - 1].getNickName().length()) << (contact[index - 1].getNickName()) << std::endl;
        // Condition ? (vrai) | (faux)
    }
}
