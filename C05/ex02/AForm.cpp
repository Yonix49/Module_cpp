/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:59:20 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/10/06 11:59:20 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "AForm.hpp"

AForm::~AForm()
{
}

AForm::AForm() : name("default form"), sign(false), gradeSign(150), gradeExecute(150) {
    
}


AForm::AForm(const std::string& name, int gradeSign, int gradeExecute)
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



AForm::AForm(const AForm& src) :
    gradeSign(src.gradeSign),
    gradeExecute(src.gradeExecute)
{
}
void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= gradeSign)
    {
        sign = true;
    }
    else
    {
        throw GradeTooLowException();
    }
}
void AForm::executeAction() const {
}

void AForm::execute(Bureaucrat const &executor) const
{
    if (!isSigned())
    {
        std::cout << executor.getName() << " cannot execute the form. It is not signed." << std::endl;
        return;
    }

    if (executor.getGrade() > getGradeExecute())
    {
        std::cout << executor.getName() << " cannot execute the form. Bureaucrat's grade is too low." << std::endl;
        return;
    }

    executeAction();
}

bool AForm::get_Grade_bool_sign() const
{
    return sign;
}

int AForm::getGradeSign() const
{
    return gradeSign;
}

int AForm::getGradeExecute() const
{
    return gradeExecute;
}

const std::string &AForm::getName() const
{
    return name;
}

bool AForm::isSigned() const
{
    return sign;
}

AForm &AForm::operator=(const AForm &src)
{
    if (this != &src)
    {
        this->sign = src.sign;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
    os << "AForm: " << form.getName() << ", Grade to Sign: " << form.getGradeSign()
       << ", Grade to Execute: " << form.getGradeExecute() << ", Signed: " << (form.isSigned() ? "Yes" : "No") << "\n";
    return os;
}
