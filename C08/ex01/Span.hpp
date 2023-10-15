/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:25:00 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/10/13 17:27:34 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

#include <iostream>

#include <cstring>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <list>
#include <stack>
#include <limits.h>
class Span
{
public:
    // Constructeurs et destructeur
    ~Span();
    Span(unsigned int N);
    Span(const Span &src);

    Span &operator=(const Span &src);



    int shortestSpan();
    int longestSpan();
    void addNumber(unsigned int nb);

void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);

    template <typename Iterator>
    void addRange(Iterator begin, Iterator end)
    {
        while (begin != end)
        {
            addNumber(*begin);
            ++begin;
        }
    }

    class Error_add : public std::exception
    {
    public:
        Error_add() {}
        virtual const char *what() const throw()
        {
            return "Number you are trying to add is out of bounds";
        }

    private:
    };

    class Error_numbers : public std::exception
    {
    public:
        Error_numbers() {}
        virtual const char *what() const throw()
        {
            return "Can't calculate the distance here";
        }

    private:
    };

private:
    Span();
    unsigned int N;
    std::vector<int> tab;
};

#include "Span.tpp"
