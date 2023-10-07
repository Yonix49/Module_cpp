/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:08:27 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/10/06 10:08:27 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>

class Bureaucrat
{
public:
    Bureaucrat(const std::string &name, int grade);
    ~Bureaucrat();
    // Bureaucrat();
    Bureaucrat &operator=(const Bureaucrat &src);

    const std::string &getName() const;
    int getGrade() const;
    void GradeIncrement(void);
    void GradeDecrement(void);

    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return "Grade is too high";
        }
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw()
        { // Marche comme un Perror en C
            return "Grade is too low";
        }
    };

private:
    const std::string &name;
    int grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif