/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:59:20 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/10/06 11:59:20 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string& name, int gradeSign, int gradeExecute)
    : name(name), gradeSign(gradeSign), gradeExecute(gradeExecute), sign(false) 
{
    if (gradeSign < 1) 
    {
        throw GradeTooHighException();
    }
     else if (gradeSign > 150)
    {
        throw GradeTooLowException();
    }
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() <= this->gradeSign) {
        this->sign = true;
    } else {
        throw GradeTooLowException();
    }
}

bool Form::getGrade_sign() const
{
    return (this->sign);
}

void Form::GradeIncrement()
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

void Form::GradeDecrement()
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


Form::Form& operator= (const Form &src)
{
    if (this != &other)
    {
        this->name = src.name;
        this->gradeSign = src.gradeSign;
        this->gradeExecute = src.gradeExecute;
        this->sign = src.sign;

    }
    return *this;
}