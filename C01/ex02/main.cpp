/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:24:15 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/09 20:04:13 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <stdlib.h>
#include <cstring>


int main() {
    std::string string = "HI THIS IS BRAIN";
    std::string *stringPTR = &string;
    std::string& stringREF = string;

    std::cout << "Adresse de string: " << &string << std::endl;
    std::cout << "Adresse pointee par stringPTR: " << stringPTR << std::endl;
    std::cout << "Adresse reference par stringREF: " << &stringREF << std::endl;

    std::cout << "La valeur de la string: " << string << std::endl;
    std::cout << "La valeur pointee par stringPTR: " << *stringPTR << std::endl;
    std::cout << "La valeur reference par stringREF: " << stringREF << std::endl;

    return 0;
}
