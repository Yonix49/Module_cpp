/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:21:52 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/15 15:57:10 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact() : firstName(""), lastName(""), nickname(""), phoneNumber(""), darkestSecret("")
{
	
}

Contact::~Contact()
{

};

std::string Contact::getFirstName() const
{
	return firstName;
}
std::string Contact::getLastName() const
{
	return lastName;
}
std::string Contact::getNickName() const
{
	return nickname;
}

void Contact::setFirstName(const std::string &firstName)
{
	this->firstName = firstName;
}
void Contact::setLastName(const std::string &lastName)
{
	this->lastName = lastName;
}
void Contact::setNickname(const std::string &nickname)
{
	this->nickname = nickname;
}
void Contact::setPhoneNumber(const std::string &phoneNumber)
{
	this->phoneNumber = phoneNumber;
}
void Contact::setDarkestSecret(const std::string &darkestSecret)
{
	this->darkestSecret = darkestSecret;
}
