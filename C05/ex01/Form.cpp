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
// Destructeur

Form::~Form()
{
}
// Constructeur
Form::Form() : name("default form"), sign(false), gradeSign(150), gradeExecute(150) {
    
}

Form::Form(const std::string& name, int gradeSign, int gradeExecute)
    : name(name), sign(false), gradeSign(gradeSign), gradeExecute(gradeExecute)
{
    // Vérification de la validité du gradeSign
    if (gradeSign < 1)
    {
        throw GradeTooHighException();
    }
    else if (gradeSign > 150)
    {
        throw GradeTooLowException();
    }
}

// Fonction pour signer le formulaire
void Form::beSigned(const Bureaucrat& bureaucrat)
{
    // Vérification du grade du bureaucrate
    if (bureaucrat.getGrade() <= this->gradeSign)
    {
        this->sign = true;
    }
    else
    {
        throw GradeTooLowException();
    }
}

// Constructeur de copie
Form::Form(const Form& src) :
    name(src.getName()),
    sign(src.isSigned()),
    gradeSign(src.getGradeSign()),
    gradeExecute(src.getGradeExecute())
{
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

// Guetteur name
const std::string& Form::getName() const
{
    return name;
}

//  Guetteur sign
bool Form::isSigned() const
{
    return sign;
}

// Opérateur d'assignation
Form& Form::operator=(const Form& src)
{
    if (this != &src)
    {
        this->sign = src.sign;
    }
    return *this;
}

// Operateur flux sortie
std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << "Form: " << form.getName() << ", Grade to Sign: " << form.getGradeSign()
       << ", Grade to Execute: " << form.getGradeExecute() << ", Signed: " << (form.isSigned() ? "Yes" : "No") << "\n";
    return os;
}
