/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:28:51 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/11/18 11:04:58 by mhajji-b         ###   ########.fr       */
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

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cout << "Error: Invalid number of arguments\n";
        return 1;
    }

    std::istringstream iss(argv[1]);
    std::string check;

    std::stack<int> numbers;
    while (iss >> check)
    {
        if (isdigit(check[0]) && check.size() == 1) {
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
            int num2 = numbers.top(); 
            numbers.pop();
            int num1 = numbers.top(); 
            numbers.pop();
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
        else {
            std::cout << "Error: Invalid check\n";
            return 1;
        }
    }

    if (numbers.size() != 1) { // il reste que le resulat dans la pile
        std::cout << "Error: Invalid expression\n";
        return 1;
    }

    std::cout << numbers.top() << '\n';

    return 0;
}
