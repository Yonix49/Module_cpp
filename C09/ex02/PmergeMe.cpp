/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:16:27 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/11/18 10:37:55 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PmergeMe.hpp"


PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe&) {}

PmergeMe& PmergeMe::operator=(const PmergeMe&) 
{
    return *this;
}

PmergeMe::PmergeMe(int ac, char **argv)
{
    std::vector<int> vec;
	std::deque<int> deq;
    int i = 1;
    while (i < ac)
    {
        parsing_elements(argv[i]);
        vec.push_back(atoi(argv[i]));
        deq.push_back(atoi(argv[i]));
        i++;
    }
	std::cout << "Before:  ";
    printContainer(vec);
    // VECTOR PART
	clock_t start = clock();
	vec = sort(vec);
	clock_t end = clock();
	double vec_time = (end - start) / static_cast<double>(CLOCKS_PER_SEC / 1000);// diff temps en ms
	//DEQUE PART 
	start = clock();
	deq = sort(deq);
	end = clock();
	double deq_time = (end - start) / static_cast<double>(CLOCKS_PER_SEC / 1000); // in ms

	std::cout << "After:   "; 
	printContainer(vec);
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << vec_time << std::endl;
	std::cout << "Time to process a range of " << vec.size() << " elements with std::deque : " << deq_time << std::endl;
}

template <typename T> void PmergeMe::printContainer(T& container)
{
    typename T::iterator it = container.begin();
    typename T::iterator ite = container.end();
    while (it != ite)
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;
}


template <typename T> void PmergeMe::insertion_sort(T& container)
{
    for(std::size_t i = 1; i < container.size(); i++)
    {
        int cle = container[i];

        int indiceComparaison = i - 1;

        while(indiceComparaison >= 0 && container[indiceComparaison] > cle)
        {
            container[indiceComparaison + 1] = container[indiceComparaison];
            indiceComparaison--;
        }

        container[indiceComparaison + 1] = cle;
    }
}

// Méthode pour trier le conteneur en utilisant l'algorithme de tri fusion
template <typename T> T PmergeMe::sort(T& container) 
{
    //Organise les elements dans le containers
    for(std::size_t i = 0; i + 1 < container.size(); i+=2)
    {
        if (container[i] < container[i + 1])	
            std::swap(container[i], container[i+1]);
    }
    
    // On divise le conteneur en deux parties
    // A = elements plus petit
    // B = elements plus grand
    T A_cont, B_cont;
    for(std::size_t i = 0; i < container.size(); i++)
    {
        if (i % 2 == 0)
            B_cont.push_back(container[i]);
        else
            A_cont.push_back(container[i]);
    }
    
    insertion_sort(A_cont);
    while (A_cont.size() != container.size())
    {
        A_cont.push_back(B_cont.back());
        B_cont.pop_back();
        insertion_sort(A_cont);
    }
    return A_cont;
}

void PmergeMe::parsing_elements(std::string av) 
{
    if (av.size() == 0)
        throw CustomException("Error");
    size_t i = 0;
    while (i < av.size()) 
    {
        if (!isdigit(av[i]))
            throw CustomException("Error");
        i++;
    };
    if (av.size() > 10 || atol(av.c_str()) > INT_MAX)
        throw CustomException("Error");
}