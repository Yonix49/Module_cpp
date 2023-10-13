/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:25:00 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/10/13 17:27:34 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

#include <string>
#include <stdexcept>

template <typename T>
class Array
{
public:
    // Constructeurs et destructeur
    Array();
    Array(unsigned int n, T *array);
    Array(const Array &src);
    ~Array();
	Array(unsigned int n);

    // Operateur d'affectation
    Array &operator=(const Array &src);
	//Operateur []
	T &operator[](unsigned int index);

    // Méthodes
    unsigned int Size() const;
    unsigned int GetIndex() const;
	
    // Classe exception
    class Error : public std::exception
    {
    public:
        Error(unsigned int index) : index(index) {}
        virtual const char *what() const throw()
        {
            return "Index is out of bounds";
        }

    private:
        unsigned int index;
    };

private:
    T *array;
    unsigned int n;
};

#include "Array.tpp"
