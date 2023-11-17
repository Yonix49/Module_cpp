/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:28:51 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/11/17 12:02:46 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include "RPN.hpp"
#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <cstdlib> 
#include <iostream>
#include <stack>
#include <sstream>
#include <string>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Error: Invalid number of arguments\n";
        return 1;
    }

    std::istringstream iss(argv[1]);
    std::string check;

    std::stack<int> numbers;
    // il faut verifier si c'est un nombre ou un operateur
    // si c'est un operateur on pop les deux derniers nombres et on fait l'operation
    // si c'est ni un nombre ni un operateur on affiche une erreur
    // si c'est un nombre superieur a 10 on affiche une erreur
    // si c'est un operateur et qu'il n'y a pas assez de nombre on affiche une erreur
    // si c'est un operateur et que le deuxieme nombre est 0 on affiche une erreur
    // si a la fin il reste plus d'un nombre on affiche une erreur
    // si a la fin il reste un nombre on l'affiche
    while (iss >> check)// chaque espace est un delimiteur  
    {
        if (isdigit(check[0])) {
            int num = std::atoi(check.c_str());
            if (num >= 10) {
                std::cout << "Error: Number must be less than 10\n";
                return 1;
            }
            numbers.push(num);
        } 
        else if (check.size() == 1 && strchr("+-*/", check[0])) {
            if (numbers.size() < 2) {
                std::cout << "Error: Not enough numbers for operation\n";
                return 1;
            }
            int num2 = numbers.top(); numbers.pop();
            int num1 = numbers.top(); numbers.pop();
            switch (check[0]) {
                case '+': numbers.push(num1 + num2); break;
                case '-': numbers.push(num1 - num2); break;
                case '*': numbers.push(num1 * num2); break;
                case '/': 
                    if (num2 == 0) {
                        std::cout << "Error: Division by zero\n";
                        return 1;
                    }
                    numbers.push(num1 / num2); 
                    break;
            }
        } 
        // If the check is not a number or operator, it is an invalid check
        else {
            std::cout << "Error: Invalid check\n";
            return 1;
        }
    }

    // After processing all checks, there should be only one number left on the stack
    if (numbers.size() != 1) {
        std::cout << "Error: Invalid expression\n";
        return 1;
    }

    // Print the result
    std::cout << numbers.top() << '\n';

    return 0;
}
