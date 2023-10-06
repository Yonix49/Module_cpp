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
// Bureaucrat::Bureaucrat()
// {
//     std::cout << "Bureaucrat default constructor called" << std::endl;
// }

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
        // std::cout << "Bureaucrat " << name << " with grade of " << grade << " called constructor" << std::endl;
    }
}

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
    // std::cout << "Bureaucrat " << name << " called destructor" << std::endl;
}

const std::string& Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
    return os;
}

void Bureaucrat::signForm(Form& form) {
    try {
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << std::endl;
    } catch (const Form::GradeTooLowException& e) {
        std::cout << name << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
    }
}
