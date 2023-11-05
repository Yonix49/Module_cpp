/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:28:51 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/11/05 14:45:17 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

int main()
{
    // Utilisation de MutantStack
    std::cout << "Utilisation de Mutant stack" << std::endl;
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    std::cout << "Top of MutantStack: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Size of MutantStack: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    
    // Itération à l'aide de l'itérateur
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    std::cout << "Elements of MutantStack:" << std::endl;
    while (it != ite)
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
    std::cout << "Utilisation de std::list" << std::endl;
    
    std::list<int> l;

    l.push_back(5);
    l.push_back(17);
    std::cout << "Top of std::list: " << l.back() << std::endl;
    l.pop_back();
    std::cout << "Size of std::list: " << l.size() << std::endl;
    l.push_back(3);
    l.push_back(5);
    l.push_back(737);

    std::list<int>::iterator lit = l.begin();
    std::list<int>::iterator lite = l.end();
    std::cout << "Elements of std::list:" << std::endl;
    while (lit != lite)
    {
        std::cout << *lit << " ";
        ++lit;
    }
    std::cout << std::endl;

    return 0;
}






