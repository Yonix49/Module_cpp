/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:04:49 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/10/08 13:03:54 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("Shrubbery Creation", 145, 137), target(target)
{
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src.getName(), src.getGradeSign(), src.getGradeExecute()) 
{
	*this = src;
}
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("default") {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm & ShrubberyCreationForm::operator= (const ShrubberyCreationForm &rhs) 
{
	if (this != &rhs)
	{
		target = rhs.target;
	}
	return *this;
}
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (isSigned() == false)
		throw NotSignedException();
	else if (executor.getGrade() > getGradeExecute())
		throw GradeTooLowException();

	std::ofstream file((target + "_shrubbery").c_str());

	if (!file.is_open())
		throw ErrorOpen();
	if (file.is_open())
	{
		file << "                                         .\n"
				"                                              .         ;  \n"
				"                 .              .              ;%     ;;   \n"
				"                   ,           ,                :;%  %;   \n"
				"                    :         ;                   :;%;'     .,\n"
				"           ,.        %;     %;            ;        %;'    ,;\n"
				"             ;       ;%;  %%;        ,     %;    ;%;    ,%;'\n"
				"              %;       %;%;      ,  ;       %;  ;%;   ,%;'\n"
				"               ;%;      %;        ;%;        % ;%;  ,%;'\n"
				"                `%;.     ;%;     %;'         `;%%;.%;'\n"
				"                 `:;%.    ;%%. %@;        %; ;@%;%'\n"
				"                    `:%;.  :;bd%;          %;@%;'\n"
				"                      `@%:.  :;%.         ;@@%;'   \n"
				"                        `@%.  `;@%.      ;@@%;         \n"
				"                          `@%%. `@%%    ;@@%;        \n"
				"                            ;@%. :@%%  %@@%;       \n"
				"                              %@bd%%%bd%%:;     \n"
				"                                #@%%%%%:;;\n"
				"                                %@@%%%::;\n"
				"                                %@@@%(o);  . '         \n"
				"                                %@@@o%;:(.,'         \n"
				"                            `.. %@@@o%::;         \n"
				"                               `)@@@o%::;         \n"
				"                                %@@(o)::;        \n"
				"                               .%@@@@%::;         \n"
				"                               ;%@@@@%::;.          \n"
				"                              ;%@@@@%%:;;;. \n"
				"                          ...;%@@@@@%%:;;;;,..\n";
		file.close();
	}
}

std::string ShrubberyCreationForm::getTarget() const
{
	return target;
}