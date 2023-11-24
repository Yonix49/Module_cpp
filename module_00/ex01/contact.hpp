/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:28:52 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/07 14:49:05 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_CONTACT
#define DEF_CONTACT

#include <iostream>
#include <string> 
#include <iomanip>
#include <cstdlib>
#include <stdlib.h>
#include <cstring>
// #include "PhoneBook.hpp"
class Contact
{
public:
	Contact(); 
	~Contact();
	void setFirstName(const std::string &firstName);
	void setLastName(const std::string &lastName);
	void setNickname(const std::string &nickname);
	void setPhoneNumber(const std::string &phoneNumber);
	void setDarkestSecret(const std::string &darkestSecret);
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickName() const;

private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
};

#endif // CONTACT_HPP
