/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:20:38 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/04/05 15:41:19 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

const std::string SHRUBBERY = 
"                                            .\n"
"                                              .\n"         
"                 .              .              ;%     ;;\n"
"                   ,           ,                :;%  %;\n"
"                    :         ;                   :;%;'     .,\n"
"           ,.        %;     %;            ;        %;'    ,;\n"
"             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
"              %;       %;%;      ,  ;       %;  ;%;   ,%;'\n"
"               ;%;      %;        ;%;        % ;%;  ,%;'\n"
"                `%;.     ;%;     %;'         `;%%;.%;'\n"
"                 `:;%.    ;%%. %@;        %; ;@%;%'\n"
"                    `:%;.  :;bd%;          %;@%;'\n"
"                      `@%:.  :;%.         ;@@%;'\n"
"                        `@%.  `;@%.      ;@@%;\n"
"                          `@%%. `@%%    ;@@%;\n"
"                           ;@%. :@%%  %@@%;\n"
"                              %@bd%%%bd%%:;\n"
"                                #@%%%%%:;;\n"
"                                %@@%%%::;\n"
"                                %@@@%(o);  . '\n"
"                                %@@@o%;:(.,'\n"
"                            `.. %@@@o%::;\n"
"                               `)@@@o%::;\n"
"                                %@@(o)::;\n"
"                               .%@@@@%::;\n"
"                               ;%@@@@%::;.\n"
"                              ;%@@@@%%:;;;. ;\n";

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): 
	AForm(target, 145, 135), target(target), minimum_auth_grade(145), minimum_exec_grade(135)
{
	this->is_signed = false;
	std::cout << "A ShrubberyCreationForm for " << this->target << " has been issued." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &base): 
	AForm(base), target(base.target), minimum_auth_grade(145), minimum_exec_grade(135)
{
	*this = base;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
	(void) rhs;
	return *this;
}

std::ostream &operator<<(std::ostream &rhs, const ShrubberyCreationForm &lhs) {

	return rhs << "A " << lhs.getName() 
		<< "'s ShrubberyCreationForm has a minimum authorization grade of " << lhs.getGradeAuth()
		<< " and a minimum execution grade of " << lhs.getGradeExec() 
		<< std::endl;
		
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "A " << this->target << " ShrubberyCreationForm has been invalidated." << std::endl;
}

void	ShrubberyCreationForm::beSigned(Bureaucrat &bureaucrat) {

	if (this->is_signed) {
		std::cout << "A " << this->target << " ShrubberyCreationForm has already been signed";
		return ;
	}

	if (bureaucrat.getGrade() > this->minimum_auth_grade) {
		throw ShrubberyCreationForm::GradeTooLowException();
	}

	this->is_signed = true;
	std::cout << bureaucrat.getName() << " signed " << this->target << std::endl;

}

void	ShrubberyCreationForm::execute(const Bureaucrat &bureaucrat) const {

	if (!this->is_signed) {
		throw std::runtime_error("ShrubberyCreationForm for " + this->target + " has not been signed before execute");
	}

	if (bureaucrat.getGrade() > this->minimum_exec_grade) {
		throw ShrubberyCreationForm::GradeTooLowException();
	}

	std::cout << "Creating a shrubbery for " << this->target << "..." << std::endl;

	std::ofstream filestream;
	filestream.open((this->target + "_shrubbery").c_str());

	if (!filestream.good()) {
		throw std::runtime_error("Cannot create a shrubbery for " + bureaucrat.getName());
	}

	filestream << SHRUBBERY << std::endl;
	filestream.close();

}
