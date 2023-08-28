/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:17:36 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/08/28 16:16:14 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_FRAGTRAP
#define DEF_FRAGTRAP
#include "ClapTrap.hpp"

class  FragTrap : public ClapTrap
{
	public:
	FragTrap();
	~FragTrap();
	FragTrap(const std::string name);
	FragTrap(const FragTrap &Other);


	FragTrap& operator=(const FragTrap &Other);
	void highFivesGuys(void);
	

	private:
	
};
#endif
