/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:28:51 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/10/15 19:01:32 by mhajji-b         ###   ########.fr       */
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
#include "Span.hpp"

int main()
{
    try
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        std::cout << "My test" << std::endl;
        
        Span vec = Span(200000);
        std::vector<int> copy(20000, 42);// TOus iniatlise a 42 
        copy[42] = 40;
        copy[19000] = 200;
        vec.addNumber(copy.begin(), copy.end());
        std::cout << vec.shortestSpan() << std::endl;
        std::cout << vec.longestSpan() << std::endl;
    }
    catch (std::exception const &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
