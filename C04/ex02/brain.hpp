/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:58:18 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/10 13:37:43 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_BRAIN
#define DEF_BRAIN
#include <cstring>
#include <iostream>
#include <string>
class Brain
{
	public:
		Brain();
		~Brain();
		Brain &operator=(const Brain &other);
		Brain(const Brain &src);
  		void copyIdeas(const Brain &other);
		std::string getIdea(int idx) const;

		void setIdea(int idx, std::string str);
	private:
		std::string ideas[100];
};

#endif