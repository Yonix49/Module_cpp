/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:10:56 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/10/06 10:10:56 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//Constructeur
Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name)
{
    if (grade < 1)
    {
        throw GradeTooHighException();
    }
    else if (grade > 150)
    {
        throw GradeTooLowException();
    }
    else
    {
        this->grade = grade;
    }
}
//Fonction incre

void Bureaucrat::GradeIncrement()
{
    if (grade > 1)
    {
        grade--;
    }
    else
    {
        throw GradeTooHighException();
    }
}
//Fonction decre
void Bureaucrat::GradeDecrement()
{
    if (grade < 150)
    {
        grade++;
    }
    else
    {
        throw GradeTooLowException();
    }
}
//Operateur surcharge =

Bureaucrat &Bureaucrat::operator = (const Bureaucrat& src)
{
	if (this != &src)
	{
		this->grade = src.grade;
	}
	return *this;
}
Bureaucrat::~Bureaucrat()
{
}
//Guetteur name

const std::string& Bureaucrat::getName() const
{
    return name;
}
//Guetteur grade
int Bureaucrat::getGrade() const
{
    return grade;
}

//Operateur ecriture 
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
    return os;
}
