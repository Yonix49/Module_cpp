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
Form::~Form()
{
}

Form::Form(const std::string &name, int gradeSign, int gradeExecute)
    : name(name), sign(false), gradeSign(gradeSign), gradeExecute(gradeExecute)
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

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= this->gradeSign)
    {
        this->sign = true;
    }
    else
    {
        throw GradeTooLowException();
    }
}

bool Form::get_Grade_bool_sign() const
{
    return sign;
}

int Form::getGradeSign() const
{
    return gradeSign;
}

int Form::getGradeExecute() const
{
    return gradeExecute;
}
const std::string &Form::getName() const
{
    return name;
}

bool Form::isSigned() const
{
    return sign;
}

Form &Form::operator=(const Form &src)
{
    if (this != &src)
    {
        this->sign = src.sign;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    os << "Form: " << form.getName() << ", Grade to Sign: " << form.getGradeSign()
       << ", Grade to Execute: " << form.getGradeExecute() << ", Signed: " << (form.isSigned() ? "Yes" : "No") << "\n";
    return os;
}