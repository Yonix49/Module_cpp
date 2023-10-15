/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:32:51 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/10/14 09:36:59 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

Span::Span()
{
	this->N = 0;
}
Span::~Span()
{
}
Span::Span(unsigned int n) : N(n), tab(0) {};// Ititialise Vec une valeur de 0 == VEC VIDE

// Span::Span(unsigned int N)
// {
// 	tab(0); // Alloue sans assigner
// }

void Span::addNumber(unsigned int nb)
{
	// tab.resize(N);
	if (tab.size() >= N)
	{
		throw Error_add();
	}
	
	tab.push_back(nb);
}

Span &Span::operator=(const Span &src)
{
	if (this != &src)
	{
		this->N = src.N;
		tab.assign(src.tab.begin(), src.tab.end()); // Copie
	}
	return *this; // Pas de & avant *this
}
void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (tab.size() >= N)
		throw std::out_of_range("Error: Out of range");
	for (std::vector<int>::iterator it = begin; it != end; it++)
	{
		addNumber(*it);
	};
}
Span::Span(const Span &src)
{
	N = src.N;
	tab.assign(src.tab.begin(), src.tab.end()); // Copie
}

int Span::shortestSpan()
{
	int span;
	if (tab.size() < 2)
	{
		throw Error_numbers();
	}
	std::sort(tab.begin(), tab.end()); // trie en ordre croissant
	int minSpan = INT_MAX;
	for (size_t i = 1; i < tab.size(); i++)
	{
		span = tab[i] - tab[i - 1];
		if (span < minSpan)
		{
			minSpan = span;
		}
	}
	return minSpan;
}
// int Span::longestSpan()// complexite quadratique tres nul avec grand tableau
// {
// 	if (tab.size() < 2)
// 	{
// 		throw Error_numbers();
// 	}
// 	std::sort(tab.begin(), tab.end()); // Trie en ordre croissant
// 	int maxSpan = 0;

// 	for (size_t i = 0; i < tab.size(); i++)
// 	{
// 		for (size_t j = i + 1; j < tab.size(); j++)
// 		{
// 			int span = (tab[j] - tab[i]);
// 			if (span > maxSpan)
// 			{
// 				maxSpan = span;
// 			}
// 		}
// 	}
// 	return maxSpan;
// }
int Span::longestSpan()
{
    if (tab.size() < 2)
    {
        throw Error_numbers();
    }

    std::sort(tab.begin(), tab.end()); // Trie en ordre croissant

    int maxSpan = tab[tab.size() - 1] - tab[0]; 
    return maxSpan;
}