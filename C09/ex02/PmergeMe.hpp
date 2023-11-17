/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:13:03 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/11/17 14:54:17 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PMERGEME_HPP 
#define PMERGEME_HPP 


#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include <map>
#include <iomanip>
#include <cmath>
#include <stack>
#include <deque>
#include <vector>
#include <climits>

class PmergeMe
{
    private:
    
public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe&);
        PmergeMe& operator=(const PmergeMe&);
        PmergeMe(int ac, char **argv);

	    template <typename T> void insertion_sort(T& container);
	    template <typename T> T sort(T& container);
	    template <typename T> void printContainer(T& container);
	    void parsing_elements(std::string av);
   
    class CustomException : public std::exception {
		private:
			const char* m_error;
		public:
			CustomException(const char * message) : m_error(message) {};
			virtual const char* what() const throw() {return m_error;};
	};
};


#endif /* PmergeMe_HPP */