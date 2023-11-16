/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:13:03 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/11/16 21:08:40 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

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

class RPN
{
    public:
        RPN();
        ~RPN();
        RPN(RPN const &);
        RPN & operator=(RPN const &);
        void    calculate(std::string calcul);
         
    private:
    

};



#endif /* RPN_HPP */