/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 17:15:05 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/10/09 19:46:58 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main ()
{
	Data *data1 = new Data;
	data1->name = "Momo";
	data1->value = 30;
	std::cout << "adress of data1: "<< data1 << " name:" << data1->name << " value: " << data1->value << std::endl;

	Data *data2 = Serializer::deserialize(Serializer::serialize(data1));
	std::cout << "adress of data2: "<< data2 << " name:" << data2->name << " value: " << data2->value << std::endl;

	delete data1;
	return 0;
};
